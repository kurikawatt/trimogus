COMPILATOR = g++
MEMCHECKER = valgrind

SRC_DIR="./src"
BUILD_DIR="./build"
BIN_DIR="./bin"

BIN_NAME=trimogus

prepare:
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi

clean:
	rm -r $(BUILD_DIR)

build: prepare
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp -o $(BIN_DIR)/$(BIN_NAME)

build_debug: prepare
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp -g3 -o $(BIN_DIR)/$(BIN_NAME)_debug

.PHONY: build build_debug