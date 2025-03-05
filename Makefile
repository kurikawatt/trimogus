COMPILATOR = g++
MEMCHECKER = valgrind

C_FLAGS =-O3

SRC_DIR="./src"
BUILD_DIR="./build"
BIN_DIR="./bin"

BIN_NAME=trimogus

prepare:
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi

clean:
	rm -r $(BUILD_DIR)

tools: prepare
	g++ -I $(SRC_DIR) -c $(SRC_DIR)/tools/*.cpp
	mv *.o $(BUILD_DIR)/

generators: tools prepare
	g++ -I $(SRC_DIR) -c $(SRC_DIR)/generators/*.cpp
	mv *.o $(BUILD_DIR)/

sorts: tools prepare
	g++ -I $(SRC_DIR) -c $(SRC_DIR)/sorts/*.cpp
	mv *.o $(BUILD_DIR)/

build: sorts generators tools
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp $(BUILD_DIR)/*.o -o $(BIN_DIR)/$(BIN_NAME) $(C_FLAGS)

native:
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp $(BUILD_DIR)/*.o -o $(BIN_DIR)/$(BIN_NAME)_native $(C_FLAGS) -march=native

debug: sorts generators tools
	$(COMPILATOR) -I $(SRC_DIR) $(SRC_DIR)/main.cpp $(BUILD_DIR)/*.o -o $(BIN_DIR)/$(BIN_NAME)_debug $(C_FLAGS)

# Pour que les règles recompilent à chaque fois, sinon on se retrouver à invoquer
#								~~ /usr/bin/ld ~~ 
.PHONY: tools generators sorts build debug