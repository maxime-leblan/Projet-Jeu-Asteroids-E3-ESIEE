#pragma once

#include "G2D.h"

struct Timer
{
    /*
    Stocke l'heure actuelle, sachant que le temps a commencé à être compté seulement à partir du démarrage du jeu
    */
    double aCurrentTime;

    /*
    Constructeur de la classe Timer.
    Démarre le compteur.
    */
    Timer();

    /*
    Accesseur du temps écoulé depuis le démarrage du jeu
    */
    double getCurrentTime();

    /*
    Indique si le timer à démarré depuis une durée supérieure à celle passée en paramètre
    pElapsedTime - durée en seconde
    */
    bool hasCountInSeconds(double pElapsedTime);

    /*
    Renvoie le temps écoulé depuis le démarrage du timer
    */
    double giveElapsedTime() const;

    /*
    Renvoie le temps restant avant d'atteindre le temps passé en paramètre
    pTimeToReach - temps de référence en secondes
    */
    double giveRemainingTimeBefore(double pTimeToReach) const;

    /*
    Réinitialise la valeur du Timer
    */
    void reset();
};