#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>
#include <cstddef>

// Buffer management constants
constexpr size_t BUFFER_POOL_SIZE = 1024;  // 1MB pages
constexpr size_t PAGE_SIZE = 4096;         // 4KB pages

// Transaction constants
constexpr uint32_t MAX_TRANSACTIONS = 1000;
constexpr uint32_t DEFAULT_TIMEOUT_MS = 5000;

// Logging constants
constexpr size_t LOG_BUFFER_SIZE = 8192;
constexpr const char* LOG_FILE_PATH = "transaction.log";

#endif // CONSTANTS_H
