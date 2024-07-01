SRC_DIR = ../src
INCLUDE_DIR = ../include
BUILD_DIR = $(SRC_DIR)
BIN_DIR = ../bin
CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR) -pthread
CFLAG = -Wall -pthread
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
EXE_FILES = $(patsubst $(SRC_DIR)/%.o, $(BIN_DIR)/%, $(OBJ_FILES))


all: create_dirs $(OBJ_FILES) $(EXE_FILES)

create_dirs:
	mkdir -p $(BIN_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%: $(BUILD_DIR)/%.o
	$(CC) $(CFLAG) $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o  $(BIN_DIR)


