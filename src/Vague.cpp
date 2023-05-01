#include "Vague.h"

using namespace std;

Vague::Vague() {
        for (int i = 0; i < 5; i++) {
        m_ennemis.push(Ennemi(TypeEnnemi::a));
    }

        for (int i = 0; i < 10; i++) {
        m_ennemis.push(Ennemi(TypeEnnemi::b));
    }

        for (int i = 0; i < 3; i++) {
        m_ennemis.push(Ennemi(TypeEnnemi::c));
    }
}

Ennemi Vague::getNextEnnemi() {
    Ennemi ennemi = m_ennemis.front();
    m_ennemis.pop();
    m_ennemis.push(ennemi);     return ennemi;
}
