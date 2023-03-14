<<<<<<< HEAD
#include "Jeu.h"
=======
#include "BatimentDefense.h"
#include "JeuModeTexte.h"
#include "Ennemi.h"
#include "StockageRessources.h"
#include "Ferme.h"
#include "BaseCentrale.h"
>>>>>>> 33ea55cbc7a5d94733ac0e18b259da0db2aac446

#include <iostream>
#include <vector>
using namespace std;

<<<<<<< HEAD
=======

class Jeu{

    public:
    //StockageRessources stockage(0,0,0,0);
    vector<Ennemi> tabEnnemi;
    vector<BatimentDefense> tabBatDef;
    vector<Ferme> TabFerme;
    BaseCentrale baseCentrale;

};





int main(){
    
    BatimentDefense bat;
    bat.setPosition(5,5);
    JeuModeTexte map(40,20,bat.getPosition(),bat.m_size,bat.m_carac);
    map.afficher();

    /*
    BatimentDefense bat;
    cout << bat.m_size;;
    cout << bat.getPosition().x;
    */


    return 0;
}
>>>>>>> 33ea55cbc7a5d94733ac0e18b259da0db2aac446
