#include "AsteroidList.h"

AsteroidList::AsteroidList()
{
    aNextAsteroidId = DEFAULT_ASTEROID_ID;
}

int AsteroidList::getNextAsteroidId()
{
    return aNextAsteroidId;
}

void AsteroidList::addAsteroid(Asteroid pAsteroid)
{
    aAsteroids[to_string(pAsteroid.getId())] = pAsteroid;
    aNextAsteroidId = (aNextAsteroidId + 1) % INT64_MAX;
    
    // cout << "Nombre d'astéroids après ajout : " << aAsteroids.size() << "\n";
}

void AsteroidList::addAsteroidSubdivisions(Asteroid pAsteroid)
{
    vector<V2> vMovingDirections = pAsteroid.giveSplitAsteroidsMovingDirection();
    Asteroid vNewAsteroid;
    int vNewRadius = (pAsteroid.getRadius())/2;
    int vNumberOfSplitLeft = pAsteroid.decreaseNumberOfSplitLeft();

    for (int i = 0; i < vMovingDirections.size(); i++)
    {
        vNewAsteroid = Asteroid(vNewRadius, aNextAsteroidId, vMovingDirections[i], pAsteroid.getPosition(), V2(INT64_MAX, INT64_MAX), vNumberOfSplitLeft);
        addAsteroid(vNewAsteroid);
    }
}

Asteroid AsteroidList::removeAsteroid(Asteroid pAsteroid)
{
    // on récupère l'astéroid concerné par la suppression
    string vId = to_string(pAsteroid.getId());
    Asteroid vAsteroid = aAsteroids[vId];

    // on supprime l'astéroid et on le renvoie
    aAsteroids.erase(vId);

    // cout << "Nombre d'astéroids après suppression de astéroide " << pAsteroid.getId() << " : " << aAsteroids.size() << "\n";

    return vAsteroid;                       
}

void AsteroidList::destroyAsteroid(Asteroid pAsteroid)
{
    // si l'astéroid peut encore se subdiviser, alors on ajoute ses subdivisions
    if (pAsteroid.canBeSplit())
    {
        addAsteroidSubdivisions(pAsteroid);
    }

    removeAsteroid(pAsteroid);
}

void AsteroidList::moveAllForward()
{
    for (auto it = aAsteroids.begin(); it != aAsteroids.end(); it++)
    {
        it->second.moveForward();
    }
}

void AsteroidList::clean()
{
    // on collecte d'abords les id des astéroides à supprimer
    vector<string> vAsteroidsIds;

    for (auto it = aAsteroids.begin(); it != aAsteroids.end(); it++)
    {
        if (!(it->second.isInTheWindow()))
        {
            vAsteroidsIds.push_back(to_string(it->second.getId()));
        }
    }

    // puis on les supprime de la liste
    for (int i = 0; i < vAsteroidsIds.size(); i++)
    {
        removeAsteroid(aAsteroids[vAsteroidsIds[i]]);
    }
}

void AsteroidList::manageAll(LaserList & pLaserList, Score & pScore)
{
    moveAllForward();
    clean();
    checkCollisionForAll(pLaserList, pScore);
}

void AsteroidList::checkCollisionForAll(LaserList & pLaserList, Score & pScore)
{
    // on va d'abords récupérer les id de tous les astéroids qui sont en collision avec un laser
    /*
    ATTENTION /!\ : Cette opération est nécessaire pour éviter de supprimer des éléments de la liste d'astéroids
    pendant son parcours, car cela peut générer l'erreur : "Segmentation fault (core dumped)" 
    */
    vector<string> vAsteroidsInCollisionWithLaserIds;
    Asteroid vCurrentAsteroidToDestroy;

    for (auto it = aAsteroids.begin(); it != aAsteroids.end(); it++)
    {
        // cout << "check asteroid " << it->first << "\n";
        if (it->second.isInCollisionWithLaserIn(pLaserList))
        {
            vAsteroidsInCollisionWithLaserIds.push_back(to_string(it->second.getId()));
            // cout << "suppression effectué sur asteroid " << it->first << "\n";
        }
    }

    // on détruit maintenant tous les astéroids concernés
    for (int i = 0; i < vAsteroidsInCollisionWithLaserIds.size(); i++)
    {
        // on augmente d'abords le score du joueur passé en paramètre
        vCurrentAsteroidToDestroy = aAsteroids[vAsteroidsInCollisionWithLaserIds[i]];
        pScore.increaseBy(pScore.giveAsteroidsScorePoints(vCurrentAsteroidToDestroy));
        destroyAsteroid(vCurrentAsteroidToDestroy);
    }
}

int AsteroidList::checkCollisionWithPlayer(RoundHitbox pPlayerHitbox)
{
    // on va d'abords récupérer les id de tous les astéroids qui sont en collision avec le joueur passé en paramètre
    /*
    ATTENTION /!\ : Cette opération est nécessaire pour éviter de supprimer des éléments de la liste d'astéroids
    pendant son parcours, car cela peut générer l'erreur : "Segmentation fault (core dumped)" 
    */
    int vTotalPlayerDamage = 0;
    vector<string> vAsteroidsInCollisionWithPlayerIds;

    for (auto it = aAsteroids.begin(); it != aAsteroids.end(); it++)
    {
        /*
        cout << "\ncheck asteroide " << it->first << "\n";
        bool vRes = (it->second).isInCollisionWith(pPlayerHitbox);
        cout << "Etat de la collision (2) : " << vRes << "\n"; 
        */
        if ((it->second).isInCollisionWith(pPlayerHitbox))
        {
            vAsteroidsInCollisionWithPlayerIds.push_back(to_string(it->second.getId()));
            /*
            cout << "l'astéroide " << it->first << " a touché le joueur !\n";
            V2 vPosPlayer = pPlayerHitbox.getPosition();
            cout << "Position du joueur : " << vPosPlayer << "\n";
            V2 vPosAst = it->second.aHitbox.getPosition();
            cout << "Position du asteroide : " << vPosAst << "\n\n";
            */
        }
    }

    // on détruit maintenant tous les astéroids concernés 
    for (int i = 0; i < vAsteroidsInCollisionWithPlayerIds.size(); i++)
    {
        // on ajoute les dégats de l'astéroide aux dégâts totaux que va subir le joueur
        vTotalPlayerDamage += aAsteroids[vAsteroidsInCollisionWithPlayerIds[i]].getDamagePoints();
        removeAsteroid(aAsteroids[vAsteroidsInCollisionWithPlayerIds[i]]);
    }

    return vTotalPlayerDamage;
}

void AsteroidList::showAll() const
{
    for (auto it = aAsteroids.begin(); it != aAsteroids.end(); it++)
    {
        it->second.show();
    }
}