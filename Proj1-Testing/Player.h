#pragma once
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Player
{
public:
	Player();
	void Init(RenderWindow& window);
	void Render();
	void Update(float elapsed, RenderWindow& window);

	Vector2f aimDirNorm;

private:
	void Move(float elapsed);
	void Aim(RenderWindow& window);
	void LookAtMouse(RenderWindow& window);
	void Shoot();

	Sprite playerSpr;
	Texture playerSprTex;
	Vector2f mousePos;
	RenderWindow *pWindow = nullptr;
};



