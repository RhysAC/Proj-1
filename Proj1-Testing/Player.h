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
	void Move(float elapsed);
	void LookAtMouse(RenderWindow& window);

private:
	Sprite playerSpr;
	Texture playerSprTex;
	RenderWindow *pWindow = nullptr;
};


