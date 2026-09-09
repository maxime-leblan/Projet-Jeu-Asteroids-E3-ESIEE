#pragma once

#include "Laser.h"
#include "RoundHitbox.h"
#include <vector>

#define FIRST_LASER_ID 1

/*
Classe gérant une liste de laser
*/
struct LaserList
{
    /*
    Liste dynamique contenant les lasers
    */
    vector<Laser> aLasers;

    /*
    Id attribué au prochain laser ajouté
    */
    int aNextLaserId;

    /*
    Constructeur par féfaut de la liste
    */
    LaserList();

    /*
    Renvoie la valeur de l'id attribué au prochain laser ajouté
    */
    int getNextLaserId();

    /*
    Ajoute un laser à la fin de la liste des lasers
    pLaser - laser à ajouter en fin de liste
    */
    void addLaser(Laser pLaser);

    /*
    Supprime le laser passé en paramètre de la liste et le renvoie
    pLaser - laser à supprimer de la liste
    Return : le laser supprimé
    */
    Laser removeLaser(Laser pLaser);

    /*
    Fait avancer tous les lasers de la liste
    */
    void moveAllForward();

    /*
    Nettoie la liste de lasers en supprimant tous les lasers qui ne sont pas dans la fenêtre de jeu
    */
    void clean();

    /*
    Fait avancer tous les lasers et supprime ceux qui ne sont plus dans la fenêtre de jeu
    */
    void manageAll();

    /*
    Vérifie si un laser rentre en collision avec la hitbox passée en paramètre.
    Si c'est le cas, elle supprime le laser de la liste
    pHitbox - hitbox avec laquelle on veut tester une collision
    Return : indique si une collision avec un laser a lieu ou non
    */
    bool checkCollisionWith(RoundHitbox pHitbox);

    /*
    Affiche tous les lasers stockés dans la liste de lasers
    */
    void showAll() const;
};