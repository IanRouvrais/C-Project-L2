CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./includes
LDFLAGS = -lm
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
EXECUTABLE = $(BIN_DIR)/main

# Colors for log messages
RED = \e[31m
GREEN = \e[32m
YELLOW = \e[33m
BLUE = \e[34m
RESET = \e[0m

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@echo -e "$(YELLOW)Linking object files$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@echo -e "$(GREEN)Build complete: $@$(RESET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo -e "$(BLUE)Compiling $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@echo -e "$(RED)Cleaning up$(RESET)"
	@rm -rf $(BUILD_DIR) $(EXECUTABLE)
	@echo -e "$(GREEN)Cleanup complete$(RESET)"

.PHONY: all clean
