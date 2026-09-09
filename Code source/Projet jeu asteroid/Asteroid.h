#pragma once

#include "UsefulFunctions.h"
#include "G2D.h"
#include "RoundHitbox.h"
#include "LaserList.h"

#define DEFAULT_SPLIT_NUMBER 2
#define SUBDIVISION_NUMBER 2
#define DISPERTION_ANGLE (M_PI/8)
#define DEFAULT_MAX_ASTEROID_SPEED 3
#define DEFAULT_MIN_ASTEROID_SPEED 1
#define DEFAULT_ASTEROID_RADIUS 30
#define MIN_DAMAGE_POINTS 5
#define DAMAGE_POINTS_FACTOR 10
#define HEIGHT_PIX 900
#define WIDTH_PIX 900

/*
Classe chargée d'implémenter un astéroide
*/
struct Asteroid
{
    /*
    Rayon de l'astéroide
    */
    int aRadius;

    /*
    Nombre de séparation encore possible de l'astéroide
    */
    int aNumberOfSplitLeft;

    /*
    Id de l'astéroide
    */
    int aId;

    /*
    Points de dégât que reçoit une entité en cas de collision avec l'astéroide
    */
    int aDamagePoints;

    /*
    Position de l'astéroid
    */
    V2 aPosition;

    /*
    Vecteur déplacement
    */
    V2 aMovingDirection;

    /*
    Vitesse de déplacement
    */
    int aMovingSpeed;

    /*
    Hitbox de l'asteroid
    */
    RoundHitbox aHitbox;

    /*
    Constructeur par défaut de la classe (ne fait rien)
    */
    Asteroid();

    /*
    Constructeur naturel de la classe. La position par défault de l'asteroid est choisie aléatoirement
    avec la méthode giveRandomDefaultPosition()
    pRadius - rayon de base de l'asteroid
    pId - id de l'astéroid
    pMovingDirection - direction de déplacement de l'astéroid, vaut (0, 0) par défaut
    pPosition - position de l'astéroid. Si la valeur par défaut n'est pas changée, alors l'astéroid
    recevra une position choisie aléatoirement au niveau des bordures du jeu
    pPlayerPosition - position du joueur, vaut (INT64_MAX, INT64_MAX) par défaut. Si sa valeur passé en paramètre
    est différente de celle-ci, alors aMovingDirection sera égal à (pPlayerPosition - aPosition) au lieu de pMovingDirection
    pNumberOfSplitLeft - nombre de subdivisions encore possible de l'astéroid
    */
    Asteroid(int pRadius, int pId, V2 pMovingDirection=V2(0, 0), V2 pPosition=V2(INT64_MAX, INT64_MAX), V2 pPlayerPosition=V2(INT64_MAX, INT64_MAX)
            , int pNumberOfSplitLeft=DEFAULT_SPLIT_NUMBER);

    /*
    Accesseur de l'id de l'astéroid
    */
    int getId();

    /*
    Accesseur du rayon de l'asteroid
    */
    int getRadius();

    /*
    Renvoie les points de dégât que reçoit une entité en cas de collision avec l'astéroide
    */
    int getDamagePoints();

    /*
    Accesseur de la position de l'astéroid
    */
    V2 getPosition();

    /*
    Modifie la position actuelle de l'astéroid par celle passée en paramètre
    pNewPosition - nouvelle position de l'astéroid
    */
    void setPosition(V2 pNewPosition);

    /*
    Vérifie si l'astéroid est toujours dans la fenêtre du jeu (entre -aRadius et HEIGH_PIX/WIDTH_PIX)
    */
    bool isInTheWindow();

    /*
    Indique si un astéroid peut encore se subdiviser ou non en trois astéroid plus petits
    */
    bool canBeSplit();

    /*
    Diminue le nombre de subdivisions possibles de l'astéroid de 1
    Return : le nombre de subdivisions possibles de l'astéroid après décrémentation
    */
    int decreaseNumberOfSplitLeft();

    /*
    Renvoie une liste contenant les directions de déplacements des nouveaux astéroids générés
    après une subdivision de l'astéroid courant
    */
    vector<V2> giveSplitAsteroidsMovingDirection();

    /*
    Fait avancer l'asteroid de pStepSize * aMovingDirection pixels avec comme direction aMovingDirection
    pStepSize - taille du saut de pixel
    */
    void makeOneStep(int pStepSize);

    /*
    Fait avancer l'asteroid de aMovingDirection
    */
    void moveForward();

    /*
    Met à jour la position de la Hitbox du joueur avec sa position actuelle
    */
    void updateHitboxPosition();

    /*
    Attribue une position de départ aléatoire se situant en dehors de la fenêtre de jeu à l'astéroid passé en paramètre
    pAsteroid - référence de l'astéroid auquel on veut donner une position aléatoire
    */
    V2 giveRandomDefaultPosition();

    /*
    Teste si l'astéroid est en collision avec un des lasers de la liste de lasers passée en paramètre
    pLaserList - référence d'une liste de laser avec laquelle on veut vérifier s'il a une collision
    */
    bool isInCollisionWithLaserIn(LaserList & pLaserList);

    /*
    Indique si l'astéroide est en collision avec une hitbox ronde
    pHitbox - hitbox avec laquelle on teste la collision avec l'astéroide
    */
    bool isInCollisionWith(RoundHitbox pHitbox);

    /*
    Affiche l'astéroid sur la fenêtre du jeu
    */
    void show() const;
};