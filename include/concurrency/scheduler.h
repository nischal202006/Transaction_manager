#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <memory>

#include "transaction/Transaction.h"
#include "storage/DataStore.h"
#include "concurrency/LockManager.h"

class Scheduler {
public:
    std::vector<Operation> createSchedule(std::vector<std::shared_ptr<Transaction>> &txns);
    void executeSchedule(std::vector<Operation> &schedule, DataStore &store);
};

#endif
