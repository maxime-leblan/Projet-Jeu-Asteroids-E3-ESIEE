#include "Asteroid.h"

Asteroid::Asteroid() {}

Asteroid::Asteroid(int pRadius, int pId, V2 pMovingDirection, V2 pPosition, V2 pPlayerPosition, int pNumberOfSplitLeft)
{
    // on définit le rayon de l'astéroide en premier car giveRandomDefaultPosition() en a besoin
    aRadius = pRadius;

    // si on a pas précisé de position à l'astéroid, on lui en assigne une aléatoirement sur les bordures du jeu
    if (pPosition.getX() == INT64_MAX && pPosition.getY() == INT64_MAX)
    {
        aPosition = giveRandomDefaultPosition();
    }
    // sinon on lui assigne la position passé en paramètre
    else
    {
        aPosition = pPosition;
    }

    // si on a pas spécifié une valeur précise pour la position du joueur, cela veut dire que l'on en a pas besoin
    // pour calculer la direction de déplacement du joueur
    if (pPlayerPosition.getX() == INT64_MAX && pPlayerPosition.getY() == INT64_MAX)
    {
        // cout << "On donne la direction de l'astéroid pour l'astéroid " << pId << "\n";
        aMovingDirection = pMovingDirection.GetNormalized();
    }
    // sinon on lui affecte comme direction la droite entre l'astéroid et le joueur
    else
    {
        // cout << "On donne la direction du joueur pour l'astéroid " << pId << "\n";
        aMovingDirection = (pPlayerPosition - aPosition).GetNormalized();
    }

    aHitbox = RoundHitbox(aPosition, pRadius);
    aNumberOfSplitLeft = pNumberOfSplitLeft;
    aMovingSpeed = getRandomInteger(DEFAULT_MIN_ASTEROID_SPEED, DEFAULT_MAX_ASTEROID_SPEED);
    aDamagePoints = aNumberOfSplitLeft * DAMAGE_POINTS_FACTOR + MIN_DAMAGE_POINTS;
    aId = pId;
}

int Asteroid::getId()
{
    return aId;
}

int Asteroid::getRadius()
{
    return aRadius;
}

V2 Asteroid::getPosition()
{
    return aPosition;
}

int Asteroid::getDamagePoints()
{
    return aDamagePoints;
}

void Asteroid::setPosition(V2 pNewPosition)
{
    aPosition = pNewPosition;
}

bool Asteroid::isInTheWindow()
{
    return aPosition.getX() <= (WIDTH_PIX + aRadius) && aPosition.getX() >= (-aRadius) && aPosition.getY() <= (HEIGHT_PIX + aRadius) && aPosition.getY() >= (-aRadius);
}

bool Asteroid::canBeSplit()
{
    return aNumberOfSplitLeft > 0;
}

int Asteroid::decreaseNumberOfSplitLeft()
{
    aNumberOfSplitLeft--;
    return aNumberOfSplitLeft;
}

void Asteroid::makeOneStep(int pStepSize)
{
    aPosition = aPosition + aMovingDirection * pStepSize;
    updateHitboxPosition();
}

void Asteroid::moveForward()
{
    makeOneStep(aMovingSpeed);
}

void Asteroid::updateHitboxPosition()
{
    aHitbox.setPosition(aPosition);
}

V2 Asteroid::giveRandomDefaultPosition()
{
    int vSide = getRandomInteger(1, 4);
    int vCoordonate = getRandomInteger(0, HEIGHT_PIX);

    if (vSide == 1)
    {
        return V2(vCoordonate, -aRadius);
    }
    else if (vSide == 2)
    {
        return V2(WIDTH_PIX + aRadius, vCoordonate);
    }
    else if (vSide == 3)
    {
        return V2(vCoordonate, HEIGHT_PIX + aRadius);
    }
    else
    {
        return V2(-aRadius, vCoordonate);
    }
}

vector<V2> Asteroid::giveSplitAsteroidsMovingDirection()
{
    // on récupère l'angle du vecteur directionnel de l'astéroid
    float vAngle = getAngle(aMovingDirection);

    /*
    cout << "aMovingDirection : " << aMovingDirection << "\n";
    V2 vNouvVect = getVectorFromAngle(vAngle);
    cout << "Inv Inv aMovingDirection : " << vNouvVect << "\n\n";
    */

    // on génère les nouvelles directions
    vector<V2> vMovingDirections;
    V2 vNewMovingDirection;

    for (int i = -(SUBDIVISION_NUMBER/2); i <= (SUBDIVISION_NUMBER/2); i++)
    {
        if (i != 0)
        {
            vNewMovingDirection = getVectorFromAngle(vAngle + i * DISPERTION_ANGLE);
            vMovingDirections.push_back(vNewMovingDirection);
        }
    }

    return vMovingDirections;
}

bool Asteroid::isInCollisionWithLaserIn(LaserList & pLaserList)
{
    return pLaserList.checkCollisionWith(aHitbox);
}

bool Asteroid::isInCollisionWith(RoundHitbox pHitbox)
{
    /*
    bool vRes = (aHitbox.collisionHitbox(pHitbox) == 1);
    cout << "Etat de la collision : " << vRes << "\n";
    */
    return (aHitbox.collisionHitbox(pHitbox) == 1);
}

void Asteroid::show() const
{
    G2D::drawCircle(aPosition, aRadius, Color::Gray, true);
}