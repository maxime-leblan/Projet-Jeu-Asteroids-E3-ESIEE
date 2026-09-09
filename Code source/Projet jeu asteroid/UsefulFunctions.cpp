#include "UsefulFunctions.h"

int getRandomInteger(int min, int max) {
    // 1. Créer un générateur de graines non déterministe (haute qualité)
    std::random_device rd;
    
    // 2. Initialiser le moteur Mersenne Twister avec la graine
    std::mt19937 gen(rd());
    
    // 3. Définir la distribution uniforme sur l'intervalle [min, max]
    std::uniform_int_distribution<int> dist(min, max);
    
    // 4. Renvoyer la valeur générée
    return dist(gen);
}