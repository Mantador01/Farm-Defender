#include "JeuModeTexte.h"
#include <iostream>

JeuModeTexte::JeuModeTexte(int largeur, int hauteur) : m_largeur(largeur), m_hauteur(hauteur) {
    m_carte = new char*[m_hauteur];
    for (int i = 0; i < m_hauteur; i++) {
        m_carte[i] = new char[m_largeur];
    }

    for (int i = 0; i < m_hauteur; i++) {
        for (int j = 0; j < m_largeur; j++) {
            if (i == 0 || j == 0 || i == m_hauteur-1 || j == m_largeur-1) {
                m_carte[i][j] = '+';
            } else {
                m_carte[i][j] = '.';
            }
        }
    }
}

JeuModeTexte::~JeuModeTexte() {
    for (int i = 0; i < m_hauteur; i++) {
        delete[] m_carte[i];
    }
    delete[] m_carte;
}

int JeuModeTexte::getLargeur() const {
    return m_largeur;
}

int JeuModeTexte::getHauteur() const {
    return m_hauteur;
}

void JeuModeTexte::afficher() const {
    for (int i = 0; i < m_hauteur; i++) {
        for (int j = 0; j < m_largeur; j++) {
            std::cout << m_carte[i][j];
        }
        std::cout << std::endl;
    }
}
