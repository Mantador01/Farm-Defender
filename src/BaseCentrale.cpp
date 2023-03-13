#include "BaseCentrale.h"
#include <chrono>

using namespace std;

BaseCentrale::BaseCentrale(StockageRessources& stockage, int pointsDeVie)
    : m_stockage(stockage), m_pointsDeVie(pointsDeVie), m_productionActive(false)
{
}

void BaseCentrale::demarrerProduction()
{
    m_productionActive = true;
    m_threadProduction = thread(&BaseCentrale::production, this);
}

void BaseCentrale::arreterProduction()
{
    m_productionActive = false;
    if (m_threadProduction.joinable()) {
        m_threadProduction.join();
    }
}

void BaseCentrale::production()
{
    while (m_productionActive) {
        this_thread::sleep_for(chrono::seconds(10));
        if (m_pointsDeVie > 0) {
            m_stockage.ajouterRessource("gold", 50);
            m_stockage.ajouterRessource("pierre", 50);
            m_stockage.ajouterRessource("bois", 50);
            m_stockage.ajouterRessource("nourriture", 50);
            m_pointsDeVie--;
        }
    }
}
