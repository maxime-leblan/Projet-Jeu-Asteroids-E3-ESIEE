#include "Laser.h"

Laser::Laser()
{
    aId = -1;
}

Laser::Laser(int pId, V2 pMovingDirection, V2 pPosition, Color pColor)
{
    aColor = pColor;
    aMovingDirection = pMovingDirection;
    aSize = LASER_SIZE;
    aMovingSpeed = LASER_SPEED;
    aPosition = pPosition;
    aDamagePoints = LASER_DAMAGE_POINTS;
    aId = pId;
}

V2 Laser::getPosition()
{
    return aPosition;
}

int Laser::getId()
{
    return aId;
}

V2 Laser::giveSegHitboxExtremity1()
{
    V2 vSegHitbox = giveSegHitbox();
    return (getPosition() - vSegHitbox);
}

V2 Laser::giveSegHitboxExtremity2()
{
    return getPosition();
}

void Laser::makeOneStep(int pStepSize)
{
    aPosition = aPosition + aMovingDirection * pStepSize;
}

void Laser::moveForward()
{
    makeOneStep(aMovingSpeed);
}

V2 Laser::giveSegHitbox()
{
    return (aMovingDirection.GetNormalized() * aSize);
}

bool Laser::isInTheWindow()
{
    return aPosition.getX() <= WIDTH_PIX && aPosition.getX() >= 0 && aPosition.getY() <= HEIGHT_PIX && aPosition.getY() >= 0;
}

void Laser::show() const
{
    // on trace plusieurs épaisseurs pour que le laser soit plus visible
    G2D::drawLine(aPosition + (aMovingDirection.GetNormalized() * aSize), aPosition, aColor);
    G2D::drawLine(aPosition + (aMovingDirection.GetNormalized() * aSize) + V2(1, 1), aPosition + V2(1, 1), aColor);
}