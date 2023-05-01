

#ifndef STOCKAGERESSOURCES_H
#define STOCKAGERESSOURCES_H

#include <string>
using namespace std;




class StockageRessources {
    private:
        int gold;
        int bois;
        int pierre;
        int nourriture;

    public:
        StockageRessources();
                void ajouterRessource(string type, int quantite);
        void retirerRessource(string type, int quantite);
        void afficherRessources();
};

#endif 