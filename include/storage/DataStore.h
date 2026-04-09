#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <map>
#include <memory>
#include <cstdint>
#include "Record.h"

class DataStore {
public:
    DataStore();
    ~DataStore();
    
    void insertRecord(std::shared_ptr<Record> record);
    std::shared_ptr<Record> getRecord(uint32_t record_id) const;
    bool deleteRecord(uint32_t record_id);
    bool updateRecord(uint32_t record_id, const std::vector<uint8_t>& data);
    
    // TODO: Implement buffer page management
    
private:
    std::map<uint32_t, std::shared_ptr<Record>> records_;
};

#endif // DATA_STORE_H
