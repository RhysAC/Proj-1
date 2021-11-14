#include "Utils.h"

using namespace std;
using namespace sf;

namespace CONSTANTS
{
	const float PI{ 3.14159265 };
}

Vector2f Getdirection(Vector2f& pos, Vector2f& otherPos)
{
	Vector2f aimDirNorm;
	Vector2f aimDir = otherPos - pos;
	// N = V / Sqrt(V.x^2 + V.y^2)
	aimDirNorm = aimDir / (static_cast<float> (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2))));
	return aimDirNorm;
}

Vector2f GetCurrentVel(Vector2f& dir, float speed)
{
	Vector2f currentVel;
	currentVel = dir * speed;
	return currentVel;
}

float LookAt(Vector2f& pos, Vector2f& otherPos)
{
	float dx = pos.x - otherPos.x;
	float dy = pos.y - otherPos.y;

	float rotation = (atan2(dy, dx)) * 180 / CONSTANTS::PI;
	return rotation;
}

float GetVectorLength(Vector2f& pos, Vector2f& otherPos)
{
	Vector2f aimDir = otherPos - pos;
	float length = aimDir.x * aimDir.x + aimDir.y * aimDir.y;
	length = sqrtf(length);
	aimDir /= length;
	return length;
}

bool CircleToCircle(const Vector2f& pos1, const Vector2f& pos2, float minDist)
{
	float dist = (pos1.x - pos2.x) * (pos1.x - pos2.x) +
		(pos1.y - pos2.y) * (pos1.y - pos2.y);
	dist = sqrtf(dist);
	return dist <= minDist;
}

Vector2f GetRandPos() 
{
	int randomDetermin = rand() % 3;
	int randX;
	int randY;
	if (randomDetermin == 0) 
	{
		randX = -200 + rand() % 1200;
		randY = -200 + rand() % 150;
	}
	else if(randomDetermin == 1)
	{
		randX =  1200 + rand() % 150;
		randY =  0 + rand() % 800;
	}
	else if (randomDetermin == 2) 
	{
		randX = -200 + rand() % 1200;
		randY = 800 + rand() % 150;
	}
	else if(randomDetermin == 3)
	{
		randX = -200 + rand() % 150;
		randY = 0 + rand() % 800;
	}

	Vector2f randPos(randX, randY);
	return randPos;
}