# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra

# Debug flags with sanitizers
DEBUG_FLAGS := -fsanitize=address,undefined

# Source and object files
SRC_DIR := ./src
INCLUDE_DIR := ./include
BIN_DIR := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC_FILES))

# Installation directory
INSTALL_DIR := /usr/local/bin

# Output target
TARGET := 2048

# Phony targets
.PHONY: all debug release run install uninstall clean

# Default target
all: debug

# Build rule
$(BIN_DIR)/$(TARGET): $(OBJ_FILES)
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) $^ -o $@

# Compile source files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) -c $< -o $@

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BIN_DIR)/$(TARGET)

# Release build
release: clean $(BIN_DIR)/$(TARGET)

# Compile and run
run: debug
	$(BIN_DIR)/$(TARGET)

# Install the executable
install: release
	cp $(BIN_DIR)/$(TARGET) $(INSTALL_DIR)

# Uninstall the executable
uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

# Clean up
clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/$(TARGET)
