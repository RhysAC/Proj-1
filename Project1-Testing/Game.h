#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Game
{
public:
	//Enum class dictating what current stage that game is at
	enum class StateMachine {
		WAITING_INIT,
		SPLASH_SCREEN,		
		PLAY			
	};
	//Default constructor
	Game();
	//Initialise data
	void Init(RenderWindow& window);
	//Update logic
	void Update(float elapsed, RenderWindow& window);
	//Render changes
	void Render(RenderWindow& window);

private:
	//The saved current state
	StateMachine mState;
	//The main player object
	Player player;
	//The main enemy object
	Enemy enemy;
	//FOnt used for the main menu
	Font font;
};

