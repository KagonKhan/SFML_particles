#include "ParticleGenerator.h"

void CircleWaveGenerator::generate(ParticleData& p, size_t startId, size_t endId)
{
	speed = 5.f * (float)(rand() % 49 + 10);
	radius = (float)(rand() % 100);

	for (int i = startId; i < endId; ++i) {
		float angle{ (float)(rand() % 360000) / 1000.f };
		auto cart_angle = sf::Vector2f{ std::cosf(angle), std::sinf(angle) };

		p.pixels[i].position = position + cart_angle * radius;
		p.velocity[i] = cart_angle * (float)speed;
	}
}

void TimeGenerator::generate(ParticleData& p, size_t startId, size_t endId)
{
	for (int i = startId; i < endId; ++i) {
		p.alive_time[i] = 0;
		p.alive_max[i] = max_time;
	}
}
#include <algorithm>
#include <random>
void ColorGenerator::generate(ParticleData& p, size_t startId, size_t endId)
{
	//std::vector<sf::Color> out;
	//std::ranges::sample(
	//	colors,
	//	std::back_inserter(out),
	//	2,
	//	std::mt19937{ std::random_device{}() }
	//);
	//start = out[0];
	//end = out[1];

	for (int i = startId; i < endId; ++i) {
		p.start_color[i] = start;
		p.end_color[i] = end;
	}
}
