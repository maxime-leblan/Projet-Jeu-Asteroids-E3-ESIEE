#pragma once

#include "AsteroidList.h"
#include "Timer.h"

#define DEFAULT_GROUPS_NUMBER 1
#define DEFAULT_WAVE_NUMBER 1
#define DEFAULT_ASTEROIDS_GROUP_SIZE 1
#define DEFAULT_TIME_BETWEEN_ASTEROIDS_GROUPS 5
#define DEFAULT_TIME_BETWEEN_WAVES 5
#define INCREASE_GROUPS_NUMBER_FREQUENCY 2
#define INCREASE_ASTEROIDS_GROUP_SIZE_FREQUENCY 2
#define WAVE_POINTS 200

struct WaveManager
{
    /*
    Nombre de groupes d'astéroides par vague
    */
    int aGroupsNumber;

    /*
    Nombre de vagues depuis le début de la partie
    */
    int aWaveNumber;

    /*
    Taille du groupe d'astéroids envoyé simultanément sur le joueur (i.e. nombre d'astéroids dans le groupe)
    */
    int aAsteroidsGroupSize;

    /*
    Indice de parcours de boucle pour la fonction launchWave()
    */
    int aI;

    /*
    Lapse de temps entre l'envoie de 2 groupes d'astéroides
    */
    double aTimeBetweenAsteroidsGroups;

    /*
    Lapse de temps entre 2 vagues
    */
    double aTimeBetweenWaves;

    /*
    Durée totale de la vague
    */
    double aCurrentWaveDuration;

    /*
    Timer gérant le temps écoulé depuis le début de la vague courante
    */
    Timer aWaveTimer;

    /*
    Constructeur naturel de la classe
    pAsteroids - liste d'astéroides dans laquelle les astéroides de chaque vagues seront stockés
    */
    WaveManager();

    /*
    Crée un nouvel astéroide et l'ajoute à la liste d'astéroids passée en paramètre
    pPlayerPosition - position du joueur sur lequel les astéroides sont lancés
    pAsteroids - référence d'une liste d'astéroides contenant l'astéroide créé
    */
    void createAsteroid(AsteroidList & pAsteroids, V2 pPlayerPosition);

    /*
    Ajoute une série d'astéroides dans la liste passée en paramètre pour pouvoir lancer un groupe d'astéroides sur le joueur
    pPlayerPosition - position du joueur sur lequel les astéroides sont lancés
    pAsteroids - référence d'une liste d'astéroides contenant les astéroide du groupe
    */
    void launchGroupOfAsteroids(AsteroidList & pAsteroids, V2 pPlayerPosition);

    /*
    Augmente occasionnelement le nombre de groupes d'astéroides envoyés et la taille d'un groupe d'astéroids
    */
    void increaseDifficulty();

    /*
    Lance une vague d'astéroides sur le joueur ou non en fonction timer gérant les vagues
    pPlayerPosition - position du joueur sur lequel les astéroides sont lancés
    pAsteroids - référence d'une liste d'astéroides contenant les astéroide de la vague
    pScore - score à augmenter à chaque fois qu'une vague se termine
    */
    void launchWave(AsteroidList & pAsteroids, V2 pPlayerPosition, Score & pScore);

    /*
    Affiche dans la fenêtre de jeu le numéro de la vague en cours
    */
    void displayWaveNumber() const;
};