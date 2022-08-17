#pragma once
#include "ParticleData.h"

class ParticleGenerator
{
public:
	virtual void generate(ParticleData& p, size_t startId, size_t endId) = 0;
};


class CircleWaveGenerator : public ParticleGenerator
{
public:
	void generate(ParticleData& p, size_t startId, size_t endId) override;


	sf::Vector2f position;
	float radius;
	float speed;
};

class TimeGenerator : public ParticleGenerator
{
public:
	void generate(ParticleData& p, size_t startId, size_t endId) override;


	float max_time{ 2.f };
};

class ColorGenerator : public ParticleGenerator
{
	static inline const std::vector<sf::Color> colors{
		sf::Color::White,
		sf::Color::Red,
		sf::Color::Green,
		sf::Color::Blue,
		sf::Color::Yellow,
		sf::Color::Magenta,
		sf::Color::Cyan
	};

public:
	void generate(ParticleData& p, size_t startId, size_t endId) override;


	sf::Color start { sf::Color::Magenta };
	sf::Color end { sf::Color::Yellow };
};