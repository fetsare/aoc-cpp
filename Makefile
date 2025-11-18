CXX = g++-14
CXXFLAGS = -std=c++14 -Wall -Wextra -O2

ifneq ($(word 2,$(MAKECMDGOALS)),)
    DAY := $(word 2,$(MAKECMDGOALS))
    $(eval $(DAY):;@:)
else
    DAY := 01
endif

DAY := $(shell printf "%02d" $(DAY))

SRC_DIR = src
DAY_DIR = $(SRC_DIR)/day$(DAY)
BIN_DIR = bin
UTILS_DIR = utils

TARGET = $(BIN_DIR)/day$(DAY)

.PHONY: help run test clean all build

help:
	@echo "Advent of Code C++ Makefile"
	@echo ""
	@echo "Usage:"
	@echo "  make build 1 - Compile solution for day 1"
	@echo "  make run 1   - Compile and run with full input"
	@echo "  make test 1  - Compile and run with test input"
	@echo "  make clean   - Remove compiled binaries"
	@echo "  make all     - Compile and run all completed days"

build: $(TARGET)

$(TARGET): $(DAY_DIR)/solution.cpp
	@mkdir -p $(BIN_DIR)
	@echo "Compiling Day $(DAY)..."
	@$(CXX) $(CXXFLAGS) -I$(UTILS_DIR) $< -o $@

run: $(TARGET)
	@echo "Running Day $(DAY) with full input..."
	@$(TARGET) $(DAY_DIR)/input.txt

test: $(TARGET)
	@echo "Running Day $(DAY) with test input..."
	@$(TARGET) $(DAY_DIR)/test_input.txt

clean:
	@echo "Cleaning compiled binaries..."
	@rm -rf $(BIN_DIR)
	@echo "Done!"

all:
	@for day in $(SRC_DIR)/day*; do \
		if [ -d "$$day" ] && [ -f "$$day/solution.cpp" ]; then \
			day_num=$$(echo $$day | sed 's|$(SRC_DIR)/day||'); \
			echo "=== Running Day $$day_num ==="; \
			$(MAKE) run DAY=$$day_num 2>/dev/null || true; \
			echo ""; \
		fi \
	done