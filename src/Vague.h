    /**
    @brief Description brève du fichier Vague.h
    Description détaillée du fichier Vague.h
    @author Ahmed/Alexandre/Sara
    @file Vague.h
    @version 1.0
    @date 01/05/2023
    */ 


#ifndef VAGUE_H
#define VAGUE_H

#include <vector>

#include <queue>
#include "Ennemi.h"


/**
@brief Classe représentant une vague d'ennemis
*/
class Vague {
public:

/**
@brief Constructeur par défaut: Initialise une vague vide sans ennemis
*/
Vague();

/**
@brief Fonction qui renvoie le prochain ennemi de la vague
@return Un ennemi de la queue d'ennemis
*/
Ennemi getNextEnnemi();


private:
std::queue<Ennemi> m_ennemis; /**< Queue contenant les ennemis de la vague */
};

#endif