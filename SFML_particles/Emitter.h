#pragma once
#include "Particle.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

class Emitter : public sf::Drawable
{
public:
	Emitter(sf::Vector2f& mouse_pos);

	void processEvents(const sf::Event& sf_event);
	void update(const sf::Clock& deltaClock);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	std::vector<Particle> particles;



	sf::Vector2f& mouse_position;
};

