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


	sf::Vector2f& mouse_position;


	const std::size_t GENERATE_AMOUNT{ 1'000'000 };

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

	struct ParticleData
	{
		std::unique_ptr<sf::Vertex[]> pixels;
		std::unique_ptr<sf::Vector2f[]> dir;

		std::size_t count{0}, alive{0};

		void generate(std::size_t amount) {
			count = amount;
			alive = 0;

			pixels.reset(new sf::Vertex[amount]);
			dir.reset(new sf::Vector2f[amount]);
		}
	};



	ParticleData particles;
};

