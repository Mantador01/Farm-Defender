<<<<<<< HEAD
/**
@brief Description brève du fichier BaseCentrale.h
Description détaillée du fichier BaseCentrale.h
@author Alexandre
@file BaseCentrale.h
@version 1.0
@date 07/03/2023
*/
/**
@brief Classe permettant la gestion des BaseCentrales.
*/

#ifndef BaseCentrale_H
#define BaseCentrale_H

#include "StockageRessources.h"

using namespace std;

class BaseCentrale {
public:
    BaseCentrale(StockageRessources& stockage, int pointsDeVie);
    void production();
    void degat(int degat);
private:
    StockageRessources& m_stockage;
    int m_pointsDeVie;
};

#endif // BaseCentrale_H
=======
/**
@brief Description brève du fichier BaseCentrale.h
Description détaillée du fichier BaseCentrale.h
@author Alexandre
@file BaseCentrale.h
@version 1.0
@date 07/03/2023
*/
/**
@brief Classe permettant la gestion des BaseCentrales.
*/

#ifndef BaseCentrale_H
#define BaseCentrale_H

#include "StockageRessources.h"

using namespace std;

class BaseCentrale {
public:
    BaseCentrale(StockageRessources& stockage, int pointsDeVie);
    void production();
    void degat(int degat);
private:
    StockageRessources& m_stockage;
    int m_pointsDeVie;
};

#endif // BaseCentrale_H
>>>>>>> 33ea55cbc7a5d94733ac0e18b259da0db2aac446
