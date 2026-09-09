#pragma once

#include <string>
#include "V2.h"
#include "G2D.h"

using namespace std;

/*
Classe chargée d'implémenter les textures d'entitées
*/
struct  Texture
{
    /*
    Variable contenant la texture représentée par une chaîne de caractères
    */
    string aTextureStr;
    /*
    Identifiant de la texture (utile pour afficher celle-ci avec G2D)
    */
    int aId;
    /*
    Taille de la texture (largeur, hauteur)
    */
    V2 aSize;

    Texture();

    /*
    Constructeur de la classe Texture
    pTextureStr - texture représentée par une chaîne de caractères
    */
    Texture(string pTextureStr);

    /*
    Affiche la texture à la position et avec l'angle passés en paramètre
    pPosition - position de la texture sur la fenêtre du jeu
    pAngle - inclinaison de la texture (=0 par défaut)
    */
    void show(V2 pPosition, float pAngle) const;

    /*
    Renvoie la taille de la texture
    */
    V2 getSize() const;
};
