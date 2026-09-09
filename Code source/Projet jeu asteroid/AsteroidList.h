#pragma once

#include <map>
#include "Asteroid.h"
#include "Player.h"

#define DEFAULT_ASTEROID_ID 1

struct AsteroidList
{
    /*
    Dictionnaire contenant la liste des astéroids
    */
    map<string, Asteroid> aAsteroids;

    /*
    Id attribué au prochain laser ajouté
    */
    int aNextAsteroidId;

    /*
    Constructeur par défaut de la classe
    */
    AsteroidList();

    /*
    Renvoie la valeur de l'id attribué au prochain astéroid ajouté
    */
    int getNextAsteroidId();

    /*
    Ajoute l'asteroid passée en paramètre à la liste
    pAsteroid - astéroid à ajouter dans la liste
    */
    void addAsteroid(Asteroid pAsteroid);

    /*
    Ajoute les subdivisions de l'astéroid passé en paramètre dans la liste d'astéroids
    pAsteroid - astéroid dont on veut ajouter les subdivisions
    */
    void addAsteroidSubdivisions(Asteroid pAsteroid);

    /*
    Supprime l'asteroid passée en paramètre de la liste
    pAsteroid - astéroid à supprimer de la liste
    */
    Asteroid removeAsteroid(Asteroid pAsteroid);

    /*
    Vérifie si l'astéroid passé en paramètre peut encore se subdiviser.
    Si oui, l'astéroid est supprimé de la liste et ses subdivisions sont ajoutées à celle-ci, sinon on enlève juste l'astéroid de la liste
    pAsteroid - astéroid que l'on veut détruire
    */
    void destroyAsteroid(Asteroid pAsteroid);

    /*
    Fait avancer tous les astéroids de la liste
    */
    void moveAllForward();

    /*
    Nettoie la liste de astéroids en supprimant tous les astéroids qui ne sont pas dans la fenêtre de jeu
    */
    void clean();

    /*
    Fait avancer tous les astéroids et supprime ceux qui ne sont plus dans la fenêtre de jeu.
    Vérifie également si des astéroids rentre en collision avec des lasers et les supprime le cas échéant, et modifie le score du joueur si besoin
    pLaserList - référence d'une liste de laser
    pScore
    */
    void manageAll(LaserList & pLaserList, Score & pScore);

    /*
    Vérifie si des asteroids sont touchés par des lasers de la liste de lasers passée en paramètre, et les supprime si c'est le cas.
    Puis augmente le score passé en paramètre en lui ajoutant les points correspondants à l'astéroide détruit
    pLaserList - référence d'une liste de laser
    pScore - référence au score du joueur que l'on veut augmenter
    */
    void checkCollisionForAll(LaserList & pLaserList, Score & pScore);

    /*
    Vérifie si un des astéroides est entrée en collision avec le joueur.
    Si c'est le cas, l'astéroide qui l'a touché est détruit
    pPlayerHitbox - hitbox du joueur
    Return : le nombre dégâts que le joueur doit subir
            vaut 0 si aucun astéroide n'est rentré en collision avec le joueur
    */
    int checkCollisionWithPlayer(RoundHitbox pPlayerHitbox);

    /*
    Affiche tous les astéroids stockés dans la liste d'astéroids
    */
    void showAll() const;
};