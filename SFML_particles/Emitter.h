#pragma once
#include <vector>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "ParticleData.h"

class Emitter : public sf::Drawable
{
public:
	Emitter(sf::Vector2f& mouse_pos);

	void processEvents(const sf::Event& sf_event);
	void update(const sf::Clock& deltaClock);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


	sf::Vector2f& mouse_position;


	const std::size_t GENERATE_AMOUNT{ 25'000 };

	const std::vector<sf::Color> colors{
		sf::Color::Black,
		sf::Color::White,
		sf::Color::Red,
		sf::Color::Green,
		sf::Color::Blue,
		sf::Color::Yellow,
		sf::Color::Magenta,
		sf::Color::Cyan
	};

	std::vector<ParticleData> particles;
};

