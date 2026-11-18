# Makefile for CAsseslets functions
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
INCLUDES = -I../My
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

# Default target

#example
#all: directories brake_status lib

all: directories lib
# Create directories

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

#example
# BrakeStatus function
#brake_status: $(OBJ_DIR)/BrakeStatus.o | directories
#	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/brake_status

#$(OBJ_DIR)/BrakeStatus.o: $(SRC_DIR)/BrakeStatus.c $(SRC_DIR)/BrakeStatus.h | directories
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | directories
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BIN_DIR)/%: $(OBJ_DIR)/%.o | directories
	$(CC) $(CFLAGS) $< -o $@

# Library target
lib: $(LIB_DIR)/libasseslets.a

#example
#$(LIB_DIR)/libasseslets.a: $(OBJ_DIR)/Hysteresis.o $(OBJ_DIR)/BrakeStatus.o $(OBJ_DIR) | directories

$(LIB_DIR)/libasseslets.a: $(OBJECTS) | directories
	ar rcs $@ $^

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

# Add rule to export the library and header files
install: lib
	cp $(LIB_DIR)/libasseslets.a ../lib/ || mkdir -p ../lib && cp $(LIB_DIR)/libasseslets.a ../lib/
	cp $(SRC_DIR)/*.h ../include/ || mkdir -p ../include && cp $(SRC_DIR)/*.h ../include/
#example
#.PHONY: all clean lib brake_status directories install
.PHONY: all clean lib directories install