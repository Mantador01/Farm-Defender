    /**
    @brief Description brève du fichier Jeu.h
    Description détaillée du fichier Jeu.h
    @author P2111020/P2018147/P2105542
    @file Jeu.h
    @version 1.0
    @date 14/03/2023
    */

    #ifndef JEU_H
    #define JEU_H

    #include "BatimentDefense.h"
    #include "JeuModeTexte.h"
    #include "Ennemi.h"
    #include "StockageRessources.h"
    #include "Ferme.h"
    #include "BaseCentrale.h"
    #include <iostream>
    #include <vector>

    class Jeu{
        public:
        /**
        * @brief stockage des ressources  gold bois pierre nourriture
        */
        StockageRessources stockage;
        /**
        * @brief tablequ dinamique qui contient tous les ennemis du jeu tant que les ennemis ne soient pas elimines
        */
        vector<Ennemi> tabEnnemi;
        /**
        * @brief tablequ dinamique qui contient tous les Batiment de Defense du jeu tant que les ennemis ne soient pas elimines
        */
        vector<BatimentDefense> tabBatDef;
         /**
        * @brief tablequ dinamique qui contient tous les Fermes du jeu tant que les ennemis ne soient pas elimines
        */
        vector<Ferme> TabFerme;

        /**
        * @brief base qui fait la gestion des resources de fermes 
        */
        //BaseCentrale baseCentrale;

         /**
        @brief deplacerEnnemis deplace tous les ennemis du jeu en prenant en compte les positionnemet des batiments
        @param tableaux dynamiques d'Ennemis, de batimets de defence, de fermess et la base centrale
        */
 
        void deplacerEnnemis();

        /**
         @brief dimention du terrain de jeu 
        */
        float jeu_largeur, jeu_hauteur;

        /**
         @brief enleve les entités qui ont ete éliminés  
        */
        void enleveEntDestruites();

        void menu() const;

        Jeu();

        ~Jeu();



        //private:
        //rien pour le moment
    
    };

    #endif







