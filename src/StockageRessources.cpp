#include "StockageRessources.h"

#include <string>

#include <iostream>

using namespace std;

StockageRessources::StockageRessources(int Rgold, int Rbois, int Rpierre, int Rnourriture) {
    gold = Rgold;
    bois = Rbois;
    pierre = Rpierre;
    nourriture = Rnourriture;
}

void StockageRessources::ajouterRessource(string type, int quantite) {
    if (type == "gold") {
        gold += quantite;
    } else if (type == "bois") {
        bois += quantite;
    } else if (type == "pierre") {
        pierre += quantite;
    } else if (type == "nourriture") {
        nourriture += quantite;
    }
}

void StockageRessources::retirerRessource(string type, int quantite) {
    if (type == "gold") {
        gold -= quantite;
    } else if (type == "bois") {
        bois -= quantite;
    } else if (type == "pierre") {
        pierre -= quantite;
    } else if (type == "nourriture") {
        nourriture -= quantite;
    }
}

void StockageRessources::afficherRessources() {
    cout << "gold : " << gold << endl;
    cout << "Bois : " << bois << endl;
    cout << "Pierre : " << pierre << endl;
    cout << "Nourriture : " << nourriture << endl;
}


