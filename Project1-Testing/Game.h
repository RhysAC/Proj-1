#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Bullets.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();

	void Init(RenderWindow& window);

	void Update(float elapsed, RenderWindow& window);

	void Render(RenderWindow& window);
	Player player;
	Bullets bullet;
	vector<Bullets> bullets;

private:
	float timer = 0;
};

