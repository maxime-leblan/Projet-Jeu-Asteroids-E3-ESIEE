#include "LaserList.h"

LaserList::LaserList()
{
    aNextLaserId = FIRST_LASER_ID;
}

int LaserList::getNextLaserId()
{
    return aNextLaserId;
}

void LaserList::addLaser(Laser pLaser)
{
    aLasers.push_back(pLaser);
    aNextLaserId++;
}

Laser LaserList::removeLaser(Laser pLaser)
{
    Laser vRes;
    for (int i = 0; i < aLasers.size(); i++)
    {
        if (aLasers[i].getId() == pLaser.getId())
        {
            vRes = aLasers[i];
            aLasers.erase(aLasers.begin() + i);
            return vRes;
        }
    }

    return Laser();
}

void LaserList::moveAllForward()
{
    for (int i = 0; i < aLasers.size(); i++)
    {
        aLasers[i].moveForward();
    }
}

void LaserList::clean()
{
    int i = 0;
    int vLasersSize = aLasers.size();

    while (i < vLasersSize)
    {
        if (!aLasers[i].isInTheWindow())
        {
            aLasers.erase(aLasers.begin() + i);
            vLasersSize = aLasers.size();
        }
        else
        {
            i++;
        }
    }
}

void LaserList::manageAll()
{
    moveAllForward();
    clean();
    // cout << "Nombre de laser en jeu : " << aLasers.size() << "\n";
}

bool LaserList::checkCollisionWith(RoundHitbox pHitbox)
{
    int vTypeCollision;
    for (int i = 0; i < aLasers.size(); i++)
    {
        vTypeCollision = pHitbox.collisionWithLaser(aLasers[i]);
        if (vTypeCollision != 0)
        {
            removeLaser(aLasers[i]);
            return true;
        }
    }
    return false;
}

void LaserList::showAll() const
{
    for (int i = 0; i < aLasers.size(); i++)
    {
        aLasers[i].show();
    }
}