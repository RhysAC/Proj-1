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