CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	cls
	./$(BIN)/$(EXECUTABLE).exe

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	rm -f $(BIN)/$(EXECUTABLE).exe

