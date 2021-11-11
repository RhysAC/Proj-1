#pragma once
#include "SFML/Graphics.hpp"

struct HudPos
{
	float posX;
	float posY;
};

class Ui
{
public:
	//Default Constructor
	Ui() {};

	/*A function to initialise certain data for the General Ui object
	*IN : Texture& tex
	*OUT : 
	*PRE_CONDITION : A valid Texture must have been passed in 
	*POST_CONDITION : The texture element of the object will be set to the passed in tex, and all other data will be initialized */
	void Init(sf::Texture& tex);

	/*A function to Update different logic relating to the Ui objects
	*IN : 
	*OUT :
	*PRE_CONDITION : There must be valid existing Ui elements to update
	*POST_CONDITION : Objects will be updated with the given instructions */
	void Update();

	/*A function to Render Ui objects
	*IN : RenderWindow& window
	*OUT :
	*PRE_CONDITION : There must be valid existing Ui elements to render, and a valid window parameter must be passed in 
	*POST_CONDITION : The Ui will be rendered */
	void Render(sf::RenderWindow& window);

	//Sprite for the Ui 
	sf::Sprite sprite;

private:

	sf::Texture spriteTex;

	sf::IntRect texRect;

	sf::Vector2f pos;
};

class GunUi : public Ui 
{
public:
	GunUi() {};

	void Init(sf::Texture& tex);

	void UpdateMag(int& ammo);

	void Render(sf::RenderWindow& window);

	sf::Sprite sprite;

	std::vector<GunUi> bullets;

private:
	// Vector for the positions that the Hud bullet elements will be rendered
	std::vector<HudPos> hudPos = { {140.f, 88.f} ,{140.f, 81.f}, {136.f, 74.f}, {131.f, 67.f}, {129.f, 60.f}, {127.f, 53.f}, {125.f, 46.f} };

	sf::Texture spriteTex;

	sf::IntRect texRect;

	sf::Vector2f pos;

	bool active;
};

