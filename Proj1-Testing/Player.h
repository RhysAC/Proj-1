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

private:
	void Move(float elapsed);
	void Aim(RenderWindow& window);
	void LookAtMouse(RenderWindow& window);

	Sprite playerSpr;
	Texture playerSprTex;
	Vector2f mousePos;
	Vector2f aimDirNorm;
	RenderWindow *pWindow = nullptr;

};


