
CC = g++
BIN=bin
OBJ=obj
SRC=src
NAZWA = sfml_framework
SOURCES= $(wildcard $(SRC)/*.cpp)
OBJECTS= $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
TARGET = $(BIN)/$(NAZWA)
all: $(OBJECTS)
	mkdir -p $(BIN)
	$(CC) $^ -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -rf $(OBJ)
	rm -rf $(BIN)
run:
	./$(TARGET)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(OBJ)
	$(CC) -I$(SRC) -c $< -o $@






