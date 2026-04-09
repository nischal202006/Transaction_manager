#include "../../include/storage/Record.h"

Record::Record(uint32_t record_id) : record_id_(record_id) {
}

Record::~Record() {
}

uint32_t Record::getRecordId() const {
    return record_id_;
}

const std::vector<uint8_t>& Record::getData() const {
    return data_;
}

void Record::setData(const std::vector<uint8_t>& data) {
    data_ = data;
}
