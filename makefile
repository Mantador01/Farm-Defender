OBJS_JEU = $(OBJ_DIR)/BatimentDefense.o $(OBJ_DIR)/Ennemi.o $(OBJ_DIR)/Vect2.o $(OBJ_DIR)/Jeu.o

FLAGS = -ggdb -Wall
CC = g++
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data

all: $(BIN_DIR)/jeu

$(BIN_DIR)/jeu: $(OBJS_JEU)
	$(CC) $(FLAGS) $(OBJS_JEU) -o $(BIN_DIR)/jeu

$(OBJ_DIR)/Vect2.o: $(SRC_DIR)/Vect2.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/Vect2.cpp -o $(OBJ_DIR)/Vect2.o

$(OBJ_DIR)/BatimentDefense.o: $(SRC_DIR)/BatimentDefense.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/BatimentDefense.cpp -o $(OBJ_DIR)/BatimentDefense.o

$(OBJ_DIR)/Ennemi.o: $(SRC_DIR)/Ennemi.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/Ennemi.cpp -o $(OBJ_DIR)/Ennemi.o

$(OBJ_DIR)/Jeu.o: $(SRC_DIR)/Jeu.cpp $(SRC_DIR)/BatimentDefense.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o

clean:
	rm -f $(OBJS_JEU) $(BIN_DIR)/jeu $(DATA_DIR)/*