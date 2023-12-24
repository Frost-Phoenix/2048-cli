# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -I./include

# Source and object files
SRC_DIR := ./src
INCLUDE_DIR := ./include
BIN_DIR := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC_FILES))

# Output target
TARGET := 2048

# Build rule
$(BIN_DIR)/$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Phony targets
.PHONY: all run clean

# Default target
all: $(BIN_DIR)/$(TARGET)

# Compile and run
run: all
	$(BIN_DIR)/$(TARGET)

# Clean up
clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/$(TARGET)
