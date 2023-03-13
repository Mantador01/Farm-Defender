#include "JeuModeTexte.h"
#include <iostream>

JeuModeTexte::JeuModeTexte(int largeur, int hauteur, Vect2 post, int size, char car) : m_largeur(largeur), m_hauteur(hauteur) {
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

    for (int i = (m_hauteur/2)-2; i<=(m_hauteur/2)+1; i++){
        for (int j = 0; j<m_largeur; j=j+(m_largeur-1)){
            m_carte[i][j] = '#';
        }
    }

    for (int i = (m_hauteur/2)-1;i <= m_hauteur/2 ; i++){
        for (int j = 0;j<=(m_largeur/2)-2;j++){
            m_carte[i][j] = '>';
        }
        for (int j = (m_largeur/2)+1;j<=m_largeur-1;j++){
            m_carte[i][j] = '<';
        }
    }

    m_carte[m_hauteur-1][(m_largeur/2)-2] = '#';
    m_carte[m_hauteur-1][(m_largeur/2)+1] = '#';
    for (int i = m_hauteur-1; i >= (m_hauteur/2)+1; i--){
        for (int j = (m_largeur/2)-1;j<=m_largeur/2;j++){
            m_carte[i][j] = '^';
        }
    }

    bool condition_verifiee = true;
    if (size == 1) {
        if (m_carte[post.y][post.x] != '.') {
            m_carte[post.y][post.x] = car;
        }
    } else {
        for (int i = post.y; i < post.y + (size/2); i++) {
            for (int j = post.x; j < post.x + (size/2); j++) {
                if (m_carte[i][j] != '.') {
                    condition_verifiee = false;
                    break;
                }
            }
            if (!condition_verifiee) {
                break;
            }

            if (i == post.y + (size/2)-1 && post.x + (size/2)-1 && condition_verifiee) {
                for (int i = post.y; i < post.y + (size/2); i++) {
                    for (int j = post.x; j < post.x + (size/2); j++) {
                        m_carte[i][j] = car;
                    }
                }
            }
        }
    }    

}

/*JeuModeTexte::JeuModeTexte(Vect2 post, int size, char car) {
    bool condition_verifiee = true;
    if (size == 1) {
        if (m_carte[post.y][post.x] != '.') {
            m_carte[post.y][post.x] = car;
        }
    } else {
        for (int i = post.y; i <= post.y + (size/2); i++) {
            for (int j = post.x; j <= post.x + (size/2); j++) {
                if (m_carte[i][j] != '.') {
                    condition_verifiee = false;
                    break;
                }
            }
            if (!condition_verifiee) {
                break;
            }

            if (i == post.y + (size/2) && post.x + (size/2) && condition_verifiee) {
                for (int i = post.y; i <= post.y + (size/2); i++) {
                    for (int j = post.x; j <= post.x + (size/2); j++) {
                        m_carte[i][j] = car;
                    }
                }
            }
        }
    }
}*/


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
