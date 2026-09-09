#include "Border.h"

Border::Border() {}

Border::Border(int pPlayerRadius, int pWidth, int pHeight)
{
    aPlayerRadius = pPlayerRadius;
    aWidth = pWidth + 2*aPlayerRadius;
    aHeight = pHeight + 2*aPlayerRadius;

    aPoints.push_back(V2(-aPlayerRadius, -aPlayerRadius));
    aPoints.push_back(V2(aWidth, -aPlayerRadius));
    aPoints.push_back(V2(aWidth, aHeight));
    aPoints.push_back(V2(-aPlayerRadius, aHeight));
    aPoints.push_back(V2(-aPlayerRadius, -aPlayerRadius));
}

void Border::show(bool pWantToShow) const
{
    if (!pWantToShow) { return; }
    for(int i = 0; i < aPoints.size() - 1; i++)
    {
        G2D::drawLine(aPoints[i], aPoints[i+1], Color::Green);
    }
}

int Border::typeOfCollisionWith(RoundHitbox pHitbox)
{
    int res;
    for(int i = 0; i < aPoints.size() - 1; i++)
    {
        res = pHitbox.collisionSeg(aPoints[i], aPoints[i+1]);
        if (res != 0)
        {
            return res;
        }
    }

    return 0;
}

bool Border::isInCollisionWith(RoundHitbox pHitbox)
{
    return typeOfCollisionWith(pHitbox) != 0;
}

bool Border::isInsideTheBorder(V2 pPosition)
{
    return (pPosition.getX() > (-aPlayerRadius)) &&
            (pPosition.getX() < (aWidth - aPlayerRadius)) &&
            (pPosition.getY() > (-aPlayerRadius)) &&
            (pPosition.getY() < (aHeight - aPlayerRadius));
}