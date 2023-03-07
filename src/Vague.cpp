#include "Vague.h"
#include "Vect2.h"

#include <iostream>
#include <ctime>

using namespace std;

Vague::Vague()
{
    enum type_ennemi tab_type = NULL;
    int ennemi_N = NULL;
}

Vague::~Vague()
{
    if (ennemi_N != NULL) {
        delete [] ennemi_N;
        ennemi_N = NULL;
    }
    if (tab_type != NULL) {
        delete [] tab_type;
        tab_type = NULL;
    }
}

Vague::Timer()const
{
    Vague a;
    int i=0;

    time_t now = time(0);

    while (true) {
        now = time(0);
        if (difftime(now, last_true_time) >= 180) { // 180 secondes = 3 minutes
            DeclancheVague(a[i]);
            i++;
        }
    }
}


Vague::DeclancheVague(Vague a)
{
    
    
    
}

