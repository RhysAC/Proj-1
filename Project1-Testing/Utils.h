#pragma once
#include "SFML/Graphics.hpp"

/* A function that works out which direction one object must move to meet another
*IN : Vector2f& pos, Vector2f& otherPos
*OUT : Vector2f aimDirNorm
*PRE_CONDITION : The passed in vectors must be valid otherwise the calculation will not work
*POST_CONDITION : we retrieve a normalized vector pointing towards the other object*/
sf::Vector2f Getdirection(sf::Vector2f& pos, sf::Vector2f& otherPos);

/* A function that determins the rate at which an object moves towards the other
*IN : Vector2f& dir
*OUT : Vector2f currentVel
*PRE_CONDITION : dir must have been previously calculated
*POST_CONDITION : we retrieve a vector that we can use to move the object*/
sf::Vector2f GetCurrentVel(sf::Vector2f& dir, float speed);

/* A function to make a given object face another
*IN : Vector2f& pos, Vector2f& otherPos
*OUT : float rotation
*PRE_CONDITION : 2 valid positions must be passed in
*POST_CONDITION : The object will rotate to face the other object using the extracted float*/
float LookAt(sf::Vector2f& pos, sf::Vector2f& otherPos);

/* A function to get the length of a vector
*IN : Vector2f& pos, Vector2f& otherPos
*OUT : float length
*PRE_CONDITION : 2 valid positions must be passed in
*POST_CONDITION : We will retrieve a float for the length of the vector*/
float GetVectorLength(sf::Vector2f& pos, sf::Vector2f& otherPos);