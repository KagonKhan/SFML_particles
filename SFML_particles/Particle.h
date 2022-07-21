#pragma once
#include "SFML/System.hpp"

struct Particle
{
	sf::Vector2f position;
	sf::Vector2f direction;
	float radius{ 1.f };
};

