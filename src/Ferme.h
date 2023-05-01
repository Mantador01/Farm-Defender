


#ifndef FERME_H
#define FERME_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;

class Ferme {
public:

    
    Ferme(StockageRessources& stockage);

    
    
    void production(bool est_vivant);

    
    void degat(int degat);

    
   bool est_vivant();
   
   
   void creation(Vect2 posi);

   
        StockageRessources* m_stockage;

    
   Vect2 get_position();


private:

    

    
    int m_pointsDeVie;

    
    Vect2 pos;
};

#endif // FERME_H