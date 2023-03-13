#include "Ferme.h"
#include <chrono>

using namespace std;

Ferme::Ferme(StockageRessources& stockage, int pointsDeVie)
    : m_stockage(stockage), m_pointsDeVie(pointsDeVie), m_productionActive(false)
{
}

void Ferme::demarrerProduction()
{
    m_productionActive = true;
    m_threadProduction = thread(&Ferme::production, this);
}

void Ferme::arreterProduction()
{
    m_productionActive = false;
    if (m_threadProduction.joinable()) {
        m_threadProduction.join();
    }
}

void Ferme::production()
{
    while (m_productionActive) {
        this_thread::sleep_for(chrono::seconds(10));
        if (m_pointsDeVie > 0) {
            m_stockage.ajouterRessource("gold", 20);
            m_stockage.ajouterRessource("pierre", 20);
            m_stockage.ajouterRessource("bois", 20);
            m_stockage.ajouterRessource("nourriture", 20);
            m_pointsDeVie--;
        }
    }
}
