#pragma once

#include "G2D.h"
#include "RoundHitbox.h"

using namespace std;

/*
Classe gérant les bordures du jeu
*/
struct Border
{
    /*
    Liste contenant tous les points constituants la bordure du jeu
    */
    vector<V2> aPoints;

    /*
    Rayon de la hitbox du joueur pour mettre un offset au périmètre de la bordure
    */
    int aPlayerRadius;

    /*
    Largeur de la bordure
    */
    int aWidth;

    /*
    Hauteur de la bordure
    */
    int aHeight;

    /*
    Constructeur par défaut de la classe (ne fait rien)
    */
    Border();

    /*
    Constructeur naturel de la classe
    pPlayerRadius - rayon de la hitbox du joueur utilisée pour le offset de la bordure
    pWidth - largeur de la bordure moins 2 fois le rayon de la hitbox du joueur
    pHeight - hauteur de la bordure moins 2 fois le rayon de la hitbox du joueur
    */
    Border(int pPlayerRadius, int pWidth, int pHeight);

    /*
    Détecte si la bordure est en collision avec la hitbox
    pHitbox - hitbox passée en paramètre
    Return : 0 s'il n'y a pas de collision avec aucun segment de la bordure
            1, 2 ou 3 sinon
    */
    int typeOfCollisionWith(RoundHitbox pHitbox);

    /*
    Renvoi vrai si la bordure est en collision avec la hitbox
    pHitbox - hitbox passée en paramètre
    */
    bool isInCollisionWith(RoundHitbox pHitbox);

    /*
    Indique si l'objet de dont la position est passé en paramètre est à l'intérieur de la bordure ou non
    pPosition - position de l'objet
    */
    bool isInsideTheBorder(V2 pPosition);
    
    /*
    Affiche la bordure du jeu sur l'écran
    pWantToShow - indique si l'on veut afficher ou non la bordure
    */
    void show(bool pWantToShow) const;
};