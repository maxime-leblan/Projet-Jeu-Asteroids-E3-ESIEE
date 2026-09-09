#include "Player.h"

Player::Player() {}

Player::Player(string pTexture, V2 pPosition)
{
    aHealthPoints = DEFAULT_HEALTH_POINTS;
    aTexture = Texture(pTexture);
    aPosition = pPosition;
    aOrientationAngle = 90;
    aMovingDirection = V2(0, 1);
    aRotationSpeed = 3;
    aMovingSpeed = 3;
    aHitbox = RoundHitbox(aPosition, (aTexture.getSize()/2).getY());
    aLasers = LaserList();
    aLaserColor = PLAYER_LASER_COLOR;
    aScore = Score();
}

RoundHitbox Player::getHitbox()
{
    return aHitbox;
}

V2 Player::getPosition()
{
    return aPosition;
}

void Player::setPosition(V2 pNewPosition)
{
    aPosition = pNewPosition;
    updateHitboxPosition();
}

LaserList & Player::getAccessToLaserList()
{
    return aLasers;
}

Score & Player::getAccessToScore()
{
    return aScore;
}

int Player::giveScoreValue() const
{
    return aScore.getTotalScore();
}

void Player::show() const
{
    // Permet de centrer la texture du joueur par rapport à sa position réelle
    V2 vTexturePosition = aPosition - (aTexture.getSize()/2);
    aTexture.show(vTexturePosition, aOrientationAngle - 90);

    // affichage de ses points de vie
    string vText = "PV : " + to_string(aHealthPoints);
    G2D::drawStringFontMono(V2(50, 800), vText, 20, 3, Color::Green);

    // affichage de son score
    aScore.display();

    // Ligne temporaire pour tracer la Hitbox du joueur
    // G2D::drawCircle(aHitbox.getPosition(), aHitbox.getRadius(), Color::Green, false);
    // Ligne temporaire pour visualiser la direction de déplacement du joueur
    // G2D::drawLine(aPosition + (aMovingDirection * 20), aPosition, Color::Yellow);
}

void Player::turn()
{
    if (G2D::isKeyPressed(Key::Q))
    {
        aOrientationAngle = (aOrientationAngle + aRotationSpeed) % 360;
        
    }
    if (G2D::isKeyPressed(Key::D))
    {
        aOrientationAngle = (aOrientationAngle - aRotationSpeed) % 360;
    }
}

void Player::updateMovingDirection()
{
    float vRadianAngle = aOrientationAngle * (M_PI/180);
    aMovingDirection = V2(cos(vRadianAngle), sin(vRadianAngle));

    /*
    cout << "aMovingDirection : " << aMovingDirection << endl;
    cout << "aPosition : " << aPosition << endl;
    cout << "aOrientationAngle : " << aOrientationAngle << "\n\n";
    */
}

void Player::moveForward()
{
    if (G2D::isKeyPressed(Key::Z))
    {
        makeOneStep(aMovingSpeed);
    }
}

void Player::makeOneStep(int pStepSize)
{
    aPosition = aPosition + aMovingDirection * pStepSize;
    updateHitboxPosition();
}

void Player::invertMovingDirection()
{
    aMovingDirection = aMovingDirection * (-1);
}

void Player::updatePosition()
{
    turn();
    updateMovingDirection();
    moveForward();
}

void Player::fire()
{
    if (G2D::keyHasBeenHit(Key::M))
    {
        // on crée un laser dont la position est juste devant le joueur, et qui pointe dans la même direction que le joueur
        Laser vNewLaser = Laser(aLasers.getNextLaserId(), aMovingDirection, aPosition + (aMovingDirection.GetNormalized() * aTexture.getSize().getY()), aLaserColor);
        aLasers.addLaser(vNewLaser);
    }
}

void Player::manageLasers()
{
    aLasers.manageAll();
}

void Player::showAllLasers() const
{
    aLasers.showAll();
}

bool Player::isAlive() const
{
    return aHealthPoints > 0;
}

void Player::takeDamage(int pDamageTaken)
{
    aHealthPoints -= pDamageTaken;
}

void Player::updateHitboxPosition()
{
    aHitbox.setPosition(aPosition);
}