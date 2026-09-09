#pragma once

#include <cmath>
#include "Texture.h"
#include "RoundHitbox.h"
#include "LaserList.h"
#include "Score.h"

using namespace std;

#define PLAYER_LASER_COLOR (Color::Red)
#define DEFAULT_HEALTH_POINTS 100;

struct Player
{
    /*
    Points de vie du joueur
    */
    int aHealthPoints;

    /*
    Position du joueur
    */
    V2 aPosition;

    /*
    Vecteur déplacement du joueur
    */
    V2 aMovingDirection;

    /*
    Vitesse de déplacement
    */
    int aMovingSpeed;

    /*
    Angle d'orientation du joueur
    */
    int aOrientationAngle;

    /*
    Vitesse de rotation du joueur
    */
    int aRotationSpeed;

    /*
    Couleur des lasers tirés par le joueur
    */
    Color aLaserColor;

    /*
    Texture du joueur
    */
    Texture aTexture;

    /*
    Score du joueur
    */
    Score aScore;

    /*
    Hitbox du joueur
    */
    RoundHitbox aHitbox;

    /*
    Liste contenant tous les lasers tirés par le joueur et encore existant dans le jeu
    */
    LaserList aLasers;

    Player();

    /*
    Constructeur de la classe Player
    pTexture - texture que l'on veut appliquer au joueur
    pPosition - position par défaut du joueur
    */
    Player(string pTexture, V2 pPosition);

    /*
    Renvoie la Hitbox du joueur
    */
    RoundHitbox getHitbox();

    /*
    Renvoie la position actuelle du joueur
    */
    V2 getPosition();

    /*
    Modificateur de aPosition. Met également à jour la position de la hitbox du joueur
    pNewPosition - nouvelle position que doit prendre le joueur
    */
    void setPosition(V2 pNewPosition);

    /*
    Renvoie une référence de la liste de lasers du joueur
    */
    LaserList & getAccessToLaserList();

    /*
    Renvoie une référence du score du joueur
    */
    Score & getAccessToScore();

    /*
    Donne la valeur du score du joueur
    */
    int giveScoreValue() const;

    /*
    Indique si le joueur est encore en vie ou non.
    Par définition, le joueur est considéré comme mort si ses points de vie sont <= 0, sinon il est considéré comme vivant
    */
    bool isAlive() const;

    /*
    Soustrait aux points de vie actuels du joueur la valeur passée en paramètre
    pDamageTaken - dégâts subis par le joueur
    */
    void takeDamage(int pDamageTaken);

    /*
    Met à jour la position de la Hitbox du joueur avec sa position actuelle
    */
    void updateHitboxPosition();

    /*
    Fait tourner le joueur sur lui-même en changeant aOrientationAngle
    si les touches Q ou D sont pressées
    */
    void turn();

    /*
    Fait avancer le joueur de pStepSize * aMovingDirection pixels avec comme direction aMovingDirection
    pStepSize - taille du saut de pixel
    */
    void makeOneStep(int pStepSize);

    /*
    Fait avancer le joueur de aMovingDirection si la touche Z est pressée
    */
    void moveForward();

    /*
    Inverse la direction de déplacement du joueur
    */
    void invertMovingDirection();

    /*
    Met à jour le vecteur déplacement du joueur en fonction de aOrientationAngle
    */
    void updateMovingDirection();
    
    /*
    Met à jour la position du joueur en fonction des touches qu'il a pressées
    */
    void updatePosition();

    /*
    Permet au joueur de tirer un laser dans la direction où il regarde s'il appuie sur la touche Up
    */
    void fire();

    /*
    Met à jour la position des lasers du joueur et supprime ceux qui ne sont plus dans la fenêtre
    */
    void manageLasers();

    /*
    Affiche tous les lasers du joueurs
    */
    void showAllLasers() const;

    /*
    Affiche le joueur sur la fenêtre du jeu, ainsi que toutes les informations qui lui sont associées
    */
    void show() const;


};