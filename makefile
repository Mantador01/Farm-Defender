OBJS_JEU = $(OBJ_DIR)/BatimentDefense.o $(OBJ_DIR)/Vect2.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Ennemi.o $(OBJ_DIR)/JeuModeTexte.o $(OBJ_DIR)/StockageRessources.o $(OBJ_DIR)/Ferme.o $(OBJ_DIR)/BaseCentrale.o
OBJS_GRAPH = $(OBJ_DIR)/BatimentDefense.o $(OBJ_DIR)/Vect2.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Ennemi.o $(OBJ_DIR)/StockageRessources.o $(OBJ_DIR)/Ferme.o $(OBJ_DIR)/main_affichage.o $(OBJ_DIR)/JeuModeGraphique.o

SDL1 = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL_mixer
SDL2 = -ISDL2
FLAGS = -ggdb -Wall
CC = g++
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data

all: $(BIN_DIR)/jeu $(BIN_DIR)/main_affichage

$(BIN_DIR)/jeu: $(OBJS_JEU)
	$(CC) $(FLAGS) $(OBJS_JEU) -o $(BIN_DIR)/jeu $(SDL1)

$(BIN_DIR)/main_affichage: $(OBJS_GRAPH)
	$(CC) $(FLAGS) $(OBJS_GRAPH) -o $(BIN_DIR)/main_affichage $(SDL1)

$(OBJ_DIR)/Vect2.o: $(SRC_DIR)/Vect2.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/Vect2.cpp -o $(OBJ_DIR)/Vect2.o $(SDL2)

$(OBJ_DIR)/BatimentDefense.o: $(SRC_DIR)/BatimentDefense.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/BatimentDefense.cpp -o $(OBJ_DIR)/BatimentDefense.o $(SDL2)

$(OBJ_DIR)/Ennemi.o: $(SRC_DIR)/Ennemi.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Ennemi.cpp -o $(OBJ_DIR)/Ennemi.o $(SDL2)

$(OBJ_DIR)/Jeu.o: $(SRC_DIR)/Jeu.cpp $(SRC_DIR)/BatimentDefense.h $(SRC_DIR)/JeuModeTexte.h $(SRC_DIR)/BaseCentrale.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o $(SDL2)
	
$(OBJ_DIR)/BaseCentrale.o: $(SRC_DIR)/BaseCentrale.cpp $(SRC_DIR)/StockageRessources.h $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/BaseCentrale.cpp  -o $(OBJ_DIR)/BaseCentrale.o $(SDL2)
	
$(OBJ_DIR)/StockageRessources.o: $(SRC_DIR)/StockageRessources.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/StockageRessources.cpp -o $(OBJ_DIR)/StockageRessources.o $(SDL2)

$(OBJ_DIR)/Ferme.o:  $(SRC_DIR)/StockageRessources.h $(SRC_DIR)/Vect2.h $(SRC_DIR)/Ferme.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/Ferme.cpp  -o $(OBJ_DIR)/Ferme.o $(SDL2)

$(OBJ_DIR)/JeuModeTexte.o: $(SRC_DIR)/JeuModeTexte.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/JeuModeTexte.cpp -o $(OBJ_DIR)/JeuModeTexte.o $(SDL2)

$(OBJ_DIR)/main_affichage.o: $(SRC_DIR)/main_affichage.cpp $(SRC_DIR)/JeuModeGraphique.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/main_affichage.cpp -o $(OBJ_DIR)/main_affichage.o $(SDL2)

$(OBJ_DIR)/JeuModeGraphique.o: $(SRC_DIR)/JeuModeGraphique.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/JeuModeGraphique.cpp -o $(OBJ_DIR)/JeuModeGraphique.o $(SDL2)

clean:
	rm -f $(OBJS_JEU) $(BIN_DIR)/jeu
