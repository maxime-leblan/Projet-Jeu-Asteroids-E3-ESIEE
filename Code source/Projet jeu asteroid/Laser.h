#pragma once

#include "G2D.h"

#define LASER_SIZE 15
#define LASER_SPEED 10
#define HEIGHT_PIX 900
#define WIDTH_PIX 900
#define LASER_DAMAGE_POINTS 10

/*
Classe représentant les tirs lasers
*/
struct Laser
{
    /*
    Couleur du laser
    */
    Color aColor;

    /*
    Direction de déplacement du laser
    */
    V2 aMovingDirection;

    /*
    Position du Laser
    */
    V2 aPosition; 

    /*
    Id du laser
    */
    int aId;

    /*
    Taille du laser
    */
    int aSize;

    /*
    Vitesse de déplacement du laser
    */
    int aMovingSpeed;

    /*
    Dégâts infligés par le laser lors d'une collision
    */
    int aDamagePoints;

    /*
    Constructeur par défaut de la classe
    ==> se contente de définir l'Id à -1 pour indiquer qu'on a créé un laser vide
    */
    Laser();

    /*
    Constructeur naturel de la classe
    pId - id du laser
    pMovingDirection - direction initiale de déplacement du laser
    pPosition - position initiale du laser
    pColor - couleur du laser
    */
    Laser(int pId, V2 pMovingDirection, V2 pPosition, Color pColor);

    /*
    Renvoie la position du Laser
    */
    V2 getPosition();

    /*
    Renvoie l'id du laser
    */
    int getId();

    /*
    Renvoie les points de dégâts qu'inflige le laser
    */
    int getDamagePoints();

    /*
    Fait avancer le laser de pStepSize * aMovingDirection pixels avec comme direction aMovingDirection
    pStepSize - taille du saut de pixel
    */
    void makeOneStep(int pStepSize);

    /*
    Fait avancer le laser de aMovingDirection
    */
    void moveForward();

    /*
    Renvoie une hitbox de type vectorielle symbolisée par le vecteur aMovingDirection normalisé et de taille aSize 
    */
    V2 giveSegHitbox();

    /*
    Renvoie la première extrémité de la Hitbox
    */
    V2 giveSegHitboxExtremity1();

    /*
    Renvoie la deuxième extrémité de la Hitbox
    */
    V2 giveSegHitboxExtremity2();

    /*
    Vérifie si le laser est toujours dans la fenêtre du jeu
    */
    bool isInTheWindow();

    /*
    Affiche le laser sur la fenêtre du jeu
    */
    void show() const;
};