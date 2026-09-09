#pragma once

#include "G2D.h"
#include "Asteroid.h"

/*
Classe gérant le score et les points que peut gagner le joueur
*/
struct Score
{
    /*
    Score total
    */
    int aTotalScore;

    /*
    Constructeur de la classe
    */
    Score();

    /*
    Accesseur de l'attribut aTotalScore
    */
    int getTotalScore() const;

    /*
    Renvoie le score qu'obtient le joueur s'il détruit l'astéroide passé en paramètre
    pAsteroid - astéroide dont on veut obtenir les points à ajouter au score en cas de destruction
    */
    int giveAsteroidsScorePoints(Asteroid pAsteroid);

    /*
    Augmente la valeur de aTotalScore en lui ajoutant la valeur passée en paramètre
    pAdditionalPoints - points que l'on veut ajouter au score total
    */
    void increaseBy(int pAdditionalPoints);

    /*
    Affiche la valeur du Score total
    */
    void display() const;
};