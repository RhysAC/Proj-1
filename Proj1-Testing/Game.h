#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();

	void Init(RenderWindow& window);

	void Update(float elapsed, RenderWindow& window);

	void Render();

	static float GetElapsedSecs() { return sElapsedSecs.asSeconds(); }
	static Time sElapsedSecs;

private:
	Player mPlayer;
};



