#include "GameData.h"

// Instanciation du constructeur de la classe

GameData::GameData()
{
    aPlayer = Player("[        R        ]"
                     "[       RRR       ]"
                     "[      RRRRR      ]"
                     "[     RRRRRRR     ]"
                     "[    RRRRRRRRR    ]"
                     "[   RRRRRRRRRRR   ]"
                     "[  RRRRRR RRRRRR  ]"
                     "[ RRRRR     RRRRR ]"
                     "[RRRR         RRRR]"
                     "[RR             RR]",
                    V2((WidthPix/2), (HeightPix/2)));
    
    aBorder = Border(aPlayer.getHitbox().getRadius(), WIDTH_PIX, HEIGHT_PIX);
    aAsteroids = AsteroidList();
    aWaveManager = WaveManager();

    // SECTION DE TESTS
    /*
    for(int i = 0; i < 5; i++)
    {
        Asteroid vAsteroid = Asteroid(DEFAULT_ASTEROID_RADIUS, aAsteroids.getNextAsteroidId(), V2(0, 0), V2(INT64_MAX, INT64_MAX), aPlayer.getPosition());
        aAsteroids.addAsteroid(vAsteroid);
        
        cout << "Position asteroid " << (i+1) << " : " << vAsteroid.aPosition << "\n";
        cout << "Est dans la fenetre : " << vAsteroid.isInTheWindow() << "\n\n";
        
    }
    */

}

bool GameData::isFinished() const
{
    return !aPlayer.isAlive();
}

void GameData::managePlayerCollisionWithBorders()
{
    if (aBorder.isInsideTheBorder(aPlayer.getPosition())) { return; }

    V2 vOldPlayerPosition = aPlayer.getPosition();
    int vPlayerRadius = aPlayer.getHitbox().getRadius();
    V2 vNewPlayerPosition;

    if (vOldPlayerPosition.getX() < (-vPlayerRadius))
    {
        vNewPlayerPosition = V2(WIDTH_PIX + vPlayerRadius, vOldPlayerPosition.getY());
    }
    else if (vOldPlayerPosition.getX() > (WIDTH_PIX + vPlayerRadius))
    {
        vNewPlayerPosition = V2(-vPlayerRadius, vOldPlayerPosition.getY());
    }
    else if (vOldPlayerPosition.getY() < (-vPlayerRadius))
    {
        vNewPlayerPosition = V2(vOldPlayerPosition.getX(), HEIGHT_PIX + vPlayerRadius);
    }
    else if (vOldPlayerPosition.getY() > (HEIGHT_PIX + vPlayerRadius))
    {
        vNewPlayerPosition = V2(vOldPlayerPosition.getX(), -vPlayerRadius);
    }

    aPlayer.setPosition(vNewPlayerPosition);
    
    // cout << "Bordure touchée !" << endl;
}

void GameData::managePlayerCollisionWithAsteroids()
{
    aPlayer.takeDamage(aAsteroids.checkCollisionWithPlayer(aPlayer.getHitbox()));
}

void GameData::managePlayerActions()
{
    // on met à jour la position du joueur en fonction des touches sur lesquelles il a appuyé
	aPlayer.updatePosition();

    aPlayer.fire();
    aPlayer.manageLasers();
}

void GameData::manageAsteroidsActions()
{
    aAsteroids.manageAll(aPlayer.getAccessToLaserList(), aPlayer.getAccessToScore());
    // cout << "Nombre d'astéroids : " << aAsteroids.aAsteroids.size() << "\n";
}

void GameData::manageWaves()
{
    aWaveManager.launchWave(aAsteroids, aPlayer.getPosition(), aPlayer.getAccessToScore());
    // cout << "Nombre d'astéroides dans GameData : " << aAsteroids.aAsteroids.size() << "\n";
}

void GameData::manageEndOfTheGame()
{
    
}

void GameData::displayEndGameScreen() const
{
    G2D::drawStringFontMono(V2((WIDTH_PIX/2 - 175), HEIGHT_PIX/2), "Game Over", 60, 5, Color::Red);

    string vScore = "Score : " + to_string(aPlayer.giveScoreValue());
    G2D::drawStringFontMono(V2((WIDTH_PIX/2 - 100), (HEIGHT_PIX/2) - 50), vScore, 20, 3, Color::Yellow);
}