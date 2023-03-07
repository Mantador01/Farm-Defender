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

//#include <BaseCentrale.h>
//#include <Ferme.h>

/**
@brief Classe permettant le stockage des ressources.
*/

class StockageRessources

{
    public:

        /**
        @brief Constructeur par défaut: Initialise la quantité à 0.
        */
        StockageRessources();

        /**
        @brief Destructeur de la classe StockageRessources
        */
        ~StockageRessources();

        /**
        @brief Fonction de stockage de la classe StockageRessources
        Permet de stocker les ressources.
        @param Entier quantité, la quantité de ressources récolter.*/
        StockageRessources(int quantite);

        /**
        @brief Fonction de de récupération de la quantite de la classe StockageRessources
        Permet de récupérer la quantité des ressources.*/
        int GetQuantite () const;

        /**
        @brief Fonction de définition de quantité de la classe StockageRessources
        Permet définir la quantité des ressources.
        @param Entier quantité, la quantité de ressources.*/
        Void SetQuantite (int quantite);

        /**
        @brief Fonction de collecte des quantité de la classe StockageRessources
        Permet de collecter les ressources.
        @param Entier quantité, la quantité de ressources.*/
        Void Collecter (int quantite);

        /**
        @brief Fonction de dépense de la classe StockageRessources
        Permet dépenser les ressources stocker.
        @param Entier quantité, la quantité de ressources.*/
        bool depenser (int quantite)

    private:

    /**
    @brief Entier quantité.
    */
    int quantite;

};

#endif // STOCKAGERESSOURCES_H
