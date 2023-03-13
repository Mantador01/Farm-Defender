#include "BatimentDefense.h"
#include "JeuModeTexte.h"
#include <iostream>
using namespace std;

int main(){
    
    BatimentDefense bat;
    bat.setPosition(19,9);
    JeuModeTexte map(40,20,bat.getPosition(),bat.m_size,bat.m_carac);
    map.afficher();

    /*
    BatimentDefense bat;
    cout << bat.m_size;;
    cout << bat.getPosition().x;
    */


    return 0;
}