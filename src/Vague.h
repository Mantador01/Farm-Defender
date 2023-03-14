/**
@brief Description brève du fichier Vague.h
Description détaillée du fichier Vague.h
@author Alexandre
@file Vague.h
@version 1.0
@date 07/03/2023
*/
/**
@brief Classe gérant les vagues d'ennemis.
*/

#ifndef VAGUE_H
#define VAGUE_H

#include <vector>
//#include "Ennemi.h"

#include <queue>
#include "Ennemi.h"

class Vague {
public:
    Vague();
    Ennemi getNextEnnemi();

private:
    std::queue<Ennemi> m_ennemis;
};



#endif // Vague_H
