#pragma once

#include "V2.h"
#include "Laser.h"

using namespace std;

struct RoundHitbox
{
    /*
    Position de la hitbox
    */
    V2 aPosition;
    
    /*
    Rayon de la hitbox
    */
    int aRadius;

    /*
    Constructeur par défaut (ne fait rien)
    */
    RoundHitbox();

    /*
    Constructeur naturel de la classe
    */
    RoundHitbox(V2 pPosition, int pRadius);

    /*
    Renvoie la position de la hitbox
    */
    V2 getPosition() const;

    /*
    Renvoie le rayon de la hitbox
    */
    int getRadius() const;

    /*
    Change la position de la hitbox
    pNewPosition - valeur de la nouvelle position
    */
    void setPosition(V2 pNewPosition);

    /*
    Détecte si la hitbox rentre en collision avec le segment (pSegExtremite2 - pSegExtremite1)
    pSegExtremite1 - coordonnées du premier point du segment
    pSegExtremite2 - coordonnées du deuxième point du segment
    Return : 0 s'il n'y a pas de collision
            2 s'il y en a une sur le segment
            1 ou 3 s'il y en a une sur le côté droit/gauche
    */
    int collisionSeg(V2 pSegExtremite1, V2 pSegExtremite2);

    /*
    Détecte si la hitbox rentre en collision avec un laser
    pLaser - coordonnées du laser
    Return : 0 s'il n'y a pas de collision
            2 s'il y en a une sur le segment
            1 ou 3 s'il y en a une sur le côté droit/gauche
    */
    int collisionWithLaser(Laser pLaser);

    /*
    Détecte si la hitbox rentre en collision avec une autre Hitbox passée en paramètre
    pHitbox - hitbox de l'objet avec lequel on pense rentrer en collision
    Return : 0 s'il n'y a pas de collision, 1 sinon
    */
    int collisionHitbox(RoundHitbox pHitbox);
};

/*
Renvoie la trajectoire du rebond par rapport à un vecteur normal suivant la loi de Snell-Descartes
V - vecteur incident
N - vecteur normal
Return : vecteur réfléchi
*/
V2 Rebond(V2 V, V2 N);