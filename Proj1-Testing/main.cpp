#include <assert.h>
#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace std;
using namespace sf;

int main() 
{
	RenderWindow window(sf::VideoMode(1200, 800), "Proj1");
	window.setFramerateLimit(60);
	Clock clock;
	Game game;
	game.Init(window);

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				window.close();
			}
		}

		float elapsed = clock.getElapsedTime().asSeconds();
		clock.restart();

		window.clear();

		game.Update(elapsed, window);

		game.Render();

		window.display();

	}

	return(0);
}
