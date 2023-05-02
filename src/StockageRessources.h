    /**
    @brief Description brève du fichier StockageRessources.h
    Description détaillée du fichier StockageRessources.h
    @author Ahmed/Alexandre/Sara
    @file StockageRessources.h
    @version 1.0
    @date 01/05/2023
    */   

#ifndef STOCKAGERESSOURCES_H
#define STOCKAGERESSOURCES_H

#include <string>
using namespace std;


/**
@brief Classe représentant un stockage de ressources dans un jeu
*/
class StockageRessources {
private:
int gold; ///< La quantité de ressources de type or stockée
int bois; ///< La quantité de ressources de type bois stockée
int pierre; ///< La quantité de ressources de type pierre stockée
int nourriture; ///< La quantité de ressources de type nourriture stockée

public:
    /**
    @brief Constructeur par défaut: Initialise toutes les ressources à 0
    */
    StockageRessources();

    /**
    @brief Ajoute une quantité de ressources de type donné
    @param type Le type de ressource à ajouter (or, bois, pierre ou nourriture)
    @param quantite La quantité de ressource à ajouter
    */
    void ajouterRessource(string type, int quantite);

    /**
    @brief Retire une quantité de ressources de type donné
    @param type Le type de ressource à retirer (or, bois, pierre ou nourriture)
    @param quantite La quantité de ressource à retirer
    */
    void retirerRessource(string type, int quantite);

    /**
    @brief Affiche les quantités de toutes les ressources stockées
    */
    void afficherRessources();

};

#endif