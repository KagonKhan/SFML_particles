#pragma once
#include "ParticleData.h"
#include <cmath>

class ParticleUpdater
{
public:
	virtual void update(float dt, ParticleData& p) = 0;
};

class EulerUpdater : public ParticleUpdater
{
	// Inherited via ParticleUpdater
	void update(float dt, ParticleData& p) override {
		const sf::Vector2f globalA = sf::Vector2f{ -90, -99 } *dt;

		auto* __restrict acc = p.acceleration.get();
		auto* __restrict vel = p.velocity.get();
		auto* __restrict pix = p.pixels.get();

		const unsigned int endId = p.alive_count;
		for (size_t i = 0; i < endId; ++i)
			acc[i] += globalA;

		for (size_t i = 0; i < endId; ++i)
			vel[i] += dt * acc[i];

		for (size_t i = 0; i < endId; ++i)
			pix[i].position += dt * vel[i];

	}
};

class TimeUpdater : public ParticleUpdater
{
	// Inherited via ParticleUpdater
	void update(float dt, ParticleData& p) override {

		const unsigned int endId = p.alive_count;
		for (size_t i = 0; i < endId; ++i) {
			p.alive_time[i] += dt;
			if (p.alive_time[i] > p.alive_max[i])
				p.kill(i);
		}

	}
};


class ColorUpdater : public ParticleUpdater
{
	sf::Color lerp(const sf::Color& a, const sf::Color& b, float t) {
		sf::Color intermediary = (b - a);
		intermediary.r *= t;
		intermediary.g *= t;
		intermediary.b *= t;

		return a + intermediary;
	}

	float norm0_1(float value, float max)
	{
		return value / max;
	}

	// Inherited via ParticleUpdater
	void update(float dt, ParticleData& p) override {

		const unsigned int endId = p.alive_count;
		for (size_t i = 0; i < endId; ++i) {
			p.pixels[i].color = lerp(p.start_color[i], p.end_color[i], norm0_1(p.alive_time[i], p.alive_max[i]));
		}

	}
};