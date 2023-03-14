/**
@brief Description brève du fichier StockageRessources.h
Description détaillée du fichier StockageRessources.h
@author Alexandre
@file StockageRessources.h
@version 1.0
@date 07/03/2023
*/

#ifndef STOCKAGERESSOURCES_H
#define STOCKAGERESSOURCES_H

#include <string>
using namespace std;


/**
@brief Classe permettant le stockage des ressources.
*/

class StockageRessources {
    private:
        int gold;
        int bois;
        int pierre;
        int nourriture;

    public:
        StockageRessources();
        //StockageRessources(int gold, int bois, int pierre, int nourriture);
        void ajouterRessource(string type, int quantite);
        void retirerRessource(string type, int quantite);
        void afficherRessources();
};

#endif // STOCKAGERESSOURCES_H
