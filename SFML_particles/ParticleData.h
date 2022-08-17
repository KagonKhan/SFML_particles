#pragma once
#include <memory>
#include "SFML/Graphics.hpp"

struct ParticleData
{
	std::unique_ptr<sf::Vertex[]>	pixels;
	std::unique_ptr<sf::Color[]>	start_color;
	std::unique_ptr<sf::Color[]>	end_color;
	std::unique_ptr<sf::Vector2f[]> velocity;
	std::unique_ptr<sf::Vector2f[]> acceleration;
	std::unique_ptr<float[]>		alive_time;
	std::unique_ptr<float[]>		alive_max;
	std::unique_ptr<bool[]>			alive;

	size_t count{ 0 };
	size_t alive_count{ 0 };

	void generate(size_t maxSize);
	void kill(size_t id);
	void wake(size_t id);
	void swapData(size_t a, size_t b);
};
