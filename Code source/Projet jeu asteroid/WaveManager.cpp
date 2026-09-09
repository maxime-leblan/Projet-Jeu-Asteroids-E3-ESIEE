#include "WaveManager.h"

WaveManager::WaveManager()
{
    aGroupsNumber = DEFAULT_GROUPS_NUMBER;
    aWaveNumber = DEFAULT_WAVE_NUMBER;
    aAsteroidsGroupSize = DEFAULT_ASTEROIDS_GROUP_SIZE;
    aWaveTimer = Timer();
    aTimeBetweenAsteroidsGroups = DEFAULT_TIME_BETWEEN_ASTEROIDS_GROUPS;
    aTimeBetweenWaves = DEFAULT_TIME_BETWEEN_WAVES;
    // Calcul de la durée de la vague en secondes
    aCurrentWaveDuration = aTimeBetweenWaves + (aGroupsNumber - 1) * aTimeBetweenAsteroidsGroups;
    aI = 0;
}

void WaveManager::createAsteroid(AsteroidList & pAsteroids, V2 pPlayerPosition)
{
    // on crée un astéroide en dehors de la zone de jeu, et qui devra foncer sur le joueur
    Asteroid vAsteroid = Asteroid(DEFAULT_ASTEROID_RADIUS, pAsteroids.getNextAsteroidId(), V2(0, 0), V2(INT64_MAX, INT64_MAX), pPlayerPosition);
    pAsteroids.addAsteroid(vAsteroid);
    // cout << "Position asteroid " << vAsteroid.getId() << " : " << vAsteroid.aPosition << "\n";
    // cout << "Est dans la fenetre : " << vAsteroid.isInTheWindow() << "\n\n";
}

void WaveManager::launchGroupOfAsteroids(AsteroidList & pAsteroids, V2 pPlayerPosition)
{
    for (int i = DEFAULT_ASTEROIDS_GROUP_SIZE; i <= aAsteroidsGroupSize; i++)
    {
        createAsteroid(pAsteroids, pPlayerPosition);
    }
}

void WaveManager::increaseDifficulty()
{
    if (aWaveNumber % INCREASE_GROUPS_NUMBER_FREQUENCY == 0)
    {
        aGroupsNumber++;
    }

    if (aWaveNumber % INCREASE_ASTEROIDS_GROUP_SIZE_FREQUENCY == 0)
    {
        aAsteroidsGroupSize++;
    }
}

void WaveManager::launchWave(AsteroidList & pAsteroids, V2 pPlayerPosition, Score & pScore)
{
    if (!aWaveTimer.hasCountInSeconds(aTimeBetweenWaves))
    {
        return;
    }

    // cout << "Fin temps attente vague " << aWaveNumber << " : " << aWaveTimer.giveElapsedTime() << "\n";

    // notre boucle while pour envoyer les goupes d'astéroides
    if (aI < aGroupsNumber)
    {
        if (aWaveTimer.hasCountInSeconds(aTimeBetweenWaves + aI * aTimeBetweenAsteroidsGroups))
        {
            // cout << "Lance groupe " << (aI+1) << " vague " << aWaveNumber << " au bout de " << aWaveTimer.giveElapsedTime() << "\n";
            launchGroupOfAsteroids(pAsteroids, pPlayerPosition);
            // cout << "Nombre d'astéroides dans la liste : " << pAsteroids.aAsteroids.size() << "\n";
            aI++;
        }
        return;
    }

    // la vague est terminée, on met à jour les variables
    // cout << "Fin vague " << aWaveNumber << " : " << aWaveTimer.giveElapsedTime() << "\n\n";
    aI = 0;
    // on rajoute des points au joueur en fonction de la vague dans laquelle il se trouve
    pScore.increaseBy(aWaveNumber * WAVE_POINTS);
    aWaveNumber++;
    increaseDifficulty();
    aWaveTimer.reset();
    // Calcul de la durée de la vague en secondes
    aCurrentWaveDuration = aTimeBetweenWaves + (aGroupsNumber - 1) * aTimeBetweenAsteroidsGroups;
}

void WaveManager::displayWaveNumber() const
{
    string vText = "Vague " + to_string(aWaveNumber);
    double vRemainingTime = aWaveTimer.giveRemainingTimeBefore(aCurrentWaveDuration);
    string vText2 = "Prochaine vague : " + to_string(vRemainingTime);
    G2D::drawStringFontMono(V2(50, 850), vText, 20, 3, Color::White);
    G2D::drawStringFontMono(V2(450, 850), vText2, 20, 3, Color::White);
}