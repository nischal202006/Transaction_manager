#ifndef RECORD_H
#define RECORD_H

#include <cstdint>
#include <vector>

class Record {
public:
    Record(uint32_t record_id);
    ~Record();
    
    uint32_t getRecordId() const;
    const std::vector<uint8_t>& getData() const;
    void setData(const std::vector<uint8_t>& data);
    
private:
    uint32_t record_id_;
    std::vector<uint8_t> data_;
};

#endif // RECORD_H
