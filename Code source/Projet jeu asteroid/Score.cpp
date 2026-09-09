#include "Score.h"

Score::Score()
{
    aTotalScore = 0;
}

int Score::getTotalScore() const
{
    return aTotalScore;
}

int Score::giveAsteroidsScorePoints(Asteroid pAsteroid)
{
    float vPoint = ( (1.0f / static_cast<float>(pAsteroid.getRadius())) * 100.0f);
    // cout << "Points de l'astéroide : " << vPoint << "\n";
    return static_cast<int>(vPoint);
}

void Score::increaseBy(int pAdditionalPoints)
{
    aTotalScore += pAdditionalPoints;
}

void Score::display() const
{
    string vText = "Score : " + to_string(aTotalScore);
    G2D::drawStringFontMono(V2(450, 800), vText, 20, 3, Color::Yellow);
}