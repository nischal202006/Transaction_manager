# CMake generated Testfile for 
# Source directory: /home/sha/Documents/Development/Transaction Manager/Transaction_manager/test
# Build directory: /home/sha/Documents/Development/Transaction Manager/Transaction_manager/build_make/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TransactionTests "/home/sha/Documents/Development/Transaction Manager/Transaction_manager/build_make/test/test_transactions")
set_tests_properties(TransactionTests PROPERTIES  _BACKTRACE_TRIPLES "/home/sha/Documents/Development/Transaction Manager/Transaction_manager/test/CMakeLists.txt;24;add_test;/home/sha/Documents/Development/Transaction Manager/Transaction_manager/test/CMakeLists.txt;0;")
add_test(DeadlockTests "/home/sha/Documents/Development/Transaction Manager/Transaction_manager/build_make/test/test_deadlock")
set_tests_properties(DeadlockTests PROPERTIES  _BACKTRACE_TRIPLES "/home/sha/Documents/Development/Transaction Manager/Transaction_manager/test/CMakeLists.txt;25;add_test;/home/sha/Documents/Development/Transaction Manager/Transaction_manager/test/CMakeLists.txt;0;")
add_test(RecoveryTests "/home/sha/Documents/Development/Transaction Manager/Transaction_manager/build_make/test/test_recovery")
set_tests_properties(RecoveryTests PROPERTIES  _BACKTRACE_TRIPLES "/home/sha/Documents/Development/Transaction Manager/Transaction_manager/test/CMakeLists.txt;26;add_test;/home/sha/Documents/Development/Transaction Manager/Transaction_manager/test/CMakeLists.txt;0;")
