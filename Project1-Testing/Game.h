#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Enemy.h"

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

	/*A function to initialise certain data for the Game
	*IN : RenderWindow& window
	*OUT :
	*PRE_CONDITION : A valid window must have been set
	*POST_CONDITION : The state will be changed to the menu screen and data will be set */
	void Init(sf::RenderWindow& window);

	/* A function to Update the logic for the Game and change states
	*IN : float elapsed, RenderWindow& window
	*OUT :
	*PRE_CONDITION : An elapsed time and render window must have been set, every referenced object must have also been initialised
	*POST_CONDITION : The Game will update it's logic and change states where appropriate */
	void Update(float elapsed, sf::RenderWindow& window);

	/* A function to Render changes to the Game
	*IN : RenderWindow& window
	*OUT :
	*PRE_CONDITION : window must have been set, and a font must have been initialised
	*POST_CONDITION : All changes will be drawn to the current window depending on the current state */
	void Render(sf::RenderWindow& window);

private:
	//The saved current state
	StateMachine mState;
	//The main player object
	Player player;
	//The main enemy object
	Enemy enemy;
	//FOnt used for the main menu
	sf::Font font;

	std::vector<GameObject> objects;
};

