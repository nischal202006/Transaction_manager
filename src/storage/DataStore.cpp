#include "../../include/storage/DataStore.h"

DataStore::DataStore()
{
}

DataStore::~DataStore()
{
}

// void DataStore::insertRecord(std::shared_ptr<Record> record) {
//     records_[record->getRecordId()] = record;
// }

// std::shared_ptr<Record> DataStore::getRecord(uint32_t record_id) const {
//     auto it = records_.find(record_id);
//     if (it != records_.end()) {
//         return it->second;
//     }
//     return nullptr;
// }

// bool DataStore::deleteRecord(uint32_t record_id) {
//     auto it = records_.find(record_id);
//     if (it != records_.end()) {
//         records_.erase(it);
//         return true;
//     }
//     return false;
// }

// bool DataStore::updateRecord(uint32_t record_id, const std::vector<uint8_t>& data) {
//     auto it = records_.find(record_id);
//     if (it != records_.end()) {
//         it->second->setData(data);
//         return true;
//     }
//     return false;
// }

void DataStore::insertRecord(Operation Op)
{
    _records[Op.key]= 1;
}
void DataStore::displayRecord(Operation Op)
{
    if (_records.find(Op.key) != _records.end())
    {
        std::cout << _records[Op.key] << std::endl;
    }
    else
    {
        std::cout << "Record is not available" << std::endl;
    }
}
void DataStore::deleteRecord(Operation Op)
{
    _records.erase(Op.key);
}
void DataStore::updateRecord(Operation Op)
{
    _records[Op.key]++;
}

void DataStore::actions(Operation Op)
{
    if (Op.type == 'R')
    {
        displayRecord(Op);
    }
    else if (Op.type == 'W')
    {
        if (_records.find(Op.key) != _records.end())
        {
            updateRecord(Op);
        }
        else
        {
            insertRecord(Op);
        }
    }

}
