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

generators: prepare
	g++ -I $(SRC_DIR) -c $(SRC_DIR)/generators/*.cpp
	mv *.o $(BUILD_DIR)/

tools: prepare
	g++ -I $(SRC_DIR) -c $(SRC_DIR)/tools/*.cpp
	mv *.o $(BUILD_DIR)/

build: generators tools
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp $(BUILD_DIR)/*.o -o $(BIN_DIR)/$(BIN_NAME)

build_debug: generators tools
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp $(BUILD_DIR)/*.o -o $(BIN_DIR)/$(BIN_NAME)_debug

.PHONY: build build_debug