#include "RoundHitbox.h"

RoundHitbox::RoundHitbox() {}

RoundHitbox::RoundHitbox(V2 pPosition, int pRadius)
{
	aPosition = pPosition;
	aRadius = pRadius;
}

V2 RoundHitbox::getPosition() const
{
	return aPosition;
}

int RoundHitbox::getRadius() const
{
	return aRadius;
}

void RoundHitbox::setPosition(V2 pNewPosition)
{
	aPosition = pNewPosition;
}

int RoundHitbox::collisionSeg(V2 pSegExtremite1, V2 pSegExtremite2)
{
	V2 AB = pSegExtremite2 - pSegExtremite1;
	V2 T = AB;
	T.normalize();
	float d = prodScal(T, aPosition - pSegExtremite1);
	if (d > 0 && d < AB.norm())
	{
		V2 P = pSegExtremite1 + d * T; // proj de C sur [AB]
		V2 PC = aPosition - P;
		if (PC.norm() < aRadius) return 2;
		else               return 0;
	}
	if ((aPosition - pSegExtremite1).norm() < aRadius) return 1;
	if ((aPosition - pSegExtremite2).norm() < aRadius) return 3;
	return 0;
}

int RoundHitbox::collisionWithLaser(Laser pLaser)
{
	return collisionSeg(pLaser.giveSegHitboxExtremity1(), pLaser.giveSegHitboxExtremity2());
}

int RoundHitbox::collisionHitbox(RoundHitbox pHitbox)
{
	V2 C1C2 = pHitbox.getPosition() - aPosition;
	// cout << "Distance entre les 2 hitbox : " << C1C2.norm() << "\n";
	// cout << "Somme des 2 rayons : " << (aRadius + pHitbox.getRadius()) << "\n";
	if (C1C2.norm() <= (aRadius + pHitbox.getRadius()))
	{
		return 1;
	}
	return 0;
}

V2 Rebond(V2 V, V2 N)
{
	N.normalize();
	V2 T = V2(N.y, -N.x);
	float vt = prodScal(V, T);
	float vn = prodScal(V, N);
	V2 R = vt * T - vn * N;
	return R;
}