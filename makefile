OBJS_JEU = $(OBJ_DIR)/BatimentDefense.o $(OBJ_DIR)/Jeu.o

FLAGS = -ggdb -Wall
CC = g++
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data

all: $(BIN_DIR)/jeu

$(BIN_DIR)/jeu: $(OBJS_JEU)
	$(CC) $(FLAGS) $(OBJS_JEU) -o $(BIN_DIR)/jeu

$(OBJ_DIR)/BatimentDefense.o: $(SRC_DIR)/BatimentDefense.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/BatimentDefense.cpp -o $(OBJ_DIR)/BatimentDefense.o

$(OBJ_DIR)/Jeu.o: $(SRC_DIR)/Jeu.cpp $(SRC_DIR)/BatimentDefense.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o

clean:
	rm -f $(OBJS_JEU) $(BIN_DIR)/jeu $(DATA_DIR)/*