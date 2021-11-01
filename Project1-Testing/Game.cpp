#include "Game.h"
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include <assert.h>
#include <sstream>
#include <string>

using namespace std;
using namespace sf;

Game::Game()
//Game starts in a 'pre-Game' stage
	: mState(StateMachine::WAITING_INIT)
{}

void Game::Init(RenderWindow& window)
{
	if (!font.loadFromFile("data/fonts/Blacklisted.ttf"))
		assert(false);

	Texture gunTex;
	if (!gunTex.loadFromFile("data/Gun_Ui.png"))
		assert(false);
	gunUi.Init(gunTex);

	Texture bulletTex;
	if (!bulletTex.loadFromFile("data/Bullet_Ui.png"))
		assert(false);
	bulletUi.Init(bulletTex);
	bulletUi.bullets.insert(bulletUi.bullets.begin(), 7, bulletUi);

	Texture backgrdTex;
	if (!backgrdTex.loadFromFile("data/Temp_Background.png"))
		assert(false);
	backGrd.Init(backgrdTex);

	player.Init(window);
	enemy.Init(window, player);
	mState = StateMachine::SPLASH_SCREEN;
}

void Game::Update(float elapsed, RenderWindow& window)
{
	switch (mState)
	{
	case StateMachine::SPLASH_SCREEN:
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			mState = StateMachine::PLAY;
		}
		break;
	case StateMachine::PLAY:
		player.Update(elapsed, window);
		enemy.Update(elapsed, window);
		bulletUi.UpdateMag(player.ammo);
		break;
	}
}

void Game::Render(RenderWindow& window)
{
	Text txt("Press Space", font, 20);
	txt.setFillColor(Color::White);
	txt.setScale(2, 2);
	FloatRect fr = txt.getGlobalBounds();
	txt.setPosition(window.getSize().x / 2.f - fr.width / 2, window.getSize().y / 2.f - fr.height / 2);

	switch (mState)
	{
	case StateMachine::SPLASH_SCREEN:
		window.draw(txt);
		break;
	case StateMachine::PLAY:
		backGrd.Render(window);
		player.Render(window);
		enemy.Render();
		bulletUi.Render(window);
		gunUi.Render(window);
		break;
	}
}
