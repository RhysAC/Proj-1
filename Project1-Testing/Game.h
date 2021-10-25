#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Game
{
public:
	enum class StateMachine {
		WAITING_INIT,
		SPLASH_SCREEN,		
		PLAY			
	};

	Game();

	void Init(RenderWindow& window);

	void Update(float elapsed, RenderWindow& window);

	void Render(RenderWindow& window);

private:
	StateMachine mState;
	Player player;
	Enemy enemy;
};

