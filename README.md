# Transaction Manager

A C++17 educational transaction manager that demonstrates key DBMS concepts:
transaction parsing, lock-based concurrency control, deadlock detection, write-ahead logging, recovery phases, and in-memory storage.

## Overview

This project simulates how transactions are interpreted and executed against shared data.
It accepts transaction definitions from `input.txt`, creates an interleaved schedule, acquires locks per operation, detects deadlocks with a wait-for graph, logs actions, and performs reads/writes on an in-memory key-value store.

## Implemented Components

### Transaction Layer (`include/transaction`, `src/transaction`)

- `Transaction`: Stores transaction ID, state, start time, and operation list.
- `TransactionManager`: Handles lifecycle (`begin`, `commit`, `abort`) and parses lines such as `T1: R(x), W(y)`.

### Concurrency Layer (`include/concurrency`, `src/concurrency`)

- `Lock`: Represents lock ownership and lock type.
- `LockManager`: Grants or denies lock requests based on compatibility, tracks dependencies in `WaitForGraph`, detects deadlocks, aborts conflicting transactions, and emits log entries through `LogManager`.
- `WaitForGraph`: Directed graph with DFS cycle detection for deadlocks.
- `Scheduler`: Builds an interleaved schedule (round-robin style) and executes operations with lock checks.

### Storage Layer (`include/storage`, `src/storage`)

- `DataStore`: In-memory key-value store where `read(key)` returns current value (default `0` if unseen) and `write(key)` increments value by `1`.
- `Record`: Record abstraction included for extensibility.

### Recovery & Logging Layer (`include/recovery`, `src/recovery`)

- `LogRecord`: WAL record model (`BEGIN`, `UPDATE`, `COMMIT`, `ABORT`, etc.).
- `LogManager`: Buffers log records, flushes to file, and exposes helper APIs `logBegin`, `logUpdate`, `logCommit`, `logAbort`.
- `RecoveryManager`: Implements recovery flow with `analysis -> redo -> undo`.

### Application Entry (`src/main.cpp`)

- Loads transactions from `input.txt`.
- Parses each transaction line into operations.
- Creates and executes schedule.
- Prints operation-by-operation runtime behavior.

## Input Format

Each line in `input.txt` is one transaction:

```text
T1: R(x), W(y), R(z)
T2: W(x), R(y)
T3: R(z), W(k)
```

`R(key)` means read, and `W(key)` means write.

## Build and Run

From the project root (`Transaction_manager`):

```bash
make
make run
```

The root `Makefile` configures CMake and builds into `build_make/`.

## Run Tests

```bash
cd build_make
ctest --output-on-failure
```

Current test targets:

- `test_transactions`
- `test_deadlock`
- `test_recovery`

## Example Runtime Output

Typical run output includes successful reads/writes, lock waits, and deadlock handling, for example:

```text
T1: READ x = 0
T2: WRITE y
...
Transaction 1 is WAITING for txn 2
Deadlock detected! Aborting txn 1
```

## Project Structure

```text
Transaction_manager/
├── include/
│   ├── transaction/
│   ├── concurrency/
│   ├── recovery/
│   ├── storage/
│   └── utils/
├── src/
│   ├── transaction/
│   ├── concurrency/
│   ├── recovery/
│   ├── storage/
│   └── main.cpp
├── test/
├── docs/
├── CMakeLists.txt
├── Makefile
└── input.txt
```

## Notes and Scope

- This is a learning-focused simulator, not a full production DBMS.
- Logging and recovery interfaces are implemented and integrated, with room for deeper persistence and rollback behavior.
- Detailed design notes are available in `docs/TRANSACTION_MANAGER.pdf`.

## License

This project is licensed under the MIT License. See `LICENSE`.
