#include "concurrency/scheduler.h"

#include <iostream>

std::vector<Operation> Scheduler::createSchedule(std::vector<std::shared_ptr<Transaction>> &txns)
{
    std::vector<Operation> schedule;
    std::vector<int> index(txns.size(), 0);

    bool remaining = true;

    while (remaining)
    {
        remaining = false;
        for (size_t i = 0; i < txns.size(); i++)
        {
            if (index[i] < txns[i]->operations.size())
            {
                schedule.push_back(txns[i]->operations[index[i]]);
                index[i]++;
                remaining = true;
            }
        }
    }
    return schedule;
}

void Scheduler::executeSchedule(std::vector<Operation> &schedule, DataStore &store)
{
    LockManager lm;

    for (const Operation& op : schedule)
    {
        uint32_t resource_id = std::hash<std::string>{}(op.key);

        LockType ltype;
        if (op.type == OperationType::READ)
            ltype = LockType::SHARED;
        else
            ltype = LockType::EXCLUSIVE;

        bool granted = lm.requestLock(op.TxnID, resource_id, ltype);

        if (granted)
        {
            if (op.type == OperationType::READ)
            {
                int val = store.read(op.key);
                std::cout << "T" << op.TxnID << ": READ " << op.key << " = " << val << std::endl;
            }
            else
            {
                store.write(op.key);
                std::cout << "T" << op.TxnID << ": WRITE " << op.key << std::endl;
            }
        }
        else
        {
            std::cout << "T" << op.TxnID << " BLOCKED on " << op.key << std::endl;
        }
    }
}
