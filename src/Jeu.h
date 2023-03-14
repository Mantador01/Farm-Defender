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
        StockageRessources stockage;
        vector<Ennemi> tabEnnemi;
        vector<BatimentDefense> tabBatDef;
        vector<Ferme> TabFerme;
        //BaseCentrale baseCentrale(stockage);
        
        //private:
    
    };

    #endif




