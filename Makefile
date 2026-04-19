BUILD_DIR := build_make
TARGET := transaction_manager

.PHONY: all configure run clean

all: configure
	$(MAKE) -C $(BUILD_DIR)

configure:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles"

run: all
	./$(BUILD_DIR)/$(TARGET)

clean:
	$(MAKE) -C $(BUILD_DIR) clean
