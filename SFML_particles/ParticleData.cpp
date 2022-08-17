#include "ParticleData.h"


void ParticleData::generate(size_t maxSize)
{
	count = maxSize;
	alive_count = 0;

	pixels.reset(new sf::Vertex[maxSize]{});
	start_color.reset(new sf::Color[maxSize]{});
	end_color.reset(new sf::Color[maxSize]{});
	velocity.reset(new sf::Vector2f[maxSize]{});
	acceleration.reset(new sf::Vector2f[maxSize]{});
	alive_time.reset(new float[maxSize] {});
	alive_max.reset(new float[maxSize] {});
	alive.reset(new bool[maxSize] {});

}

void ParticleData::kill(size_t id)
{
	if (alive_count > 0)
	{
		alive[id] = false;
		swapData(id, alive_count - 1);
		alive_count--;
	}
}

void ParticleData::wake(size_t id)
{
	if (alive_count < count)
	{
		alive[id] = true;
		swapData(id, alive_count);
		alive_count++;
		
	}
}

void ParticleData::swapData(size_t a, size_t b)
{
	std::swap(pixels[a], pixels[b]);
	std::swap(start_color[a], start_color[b]);
	std::swap(end_color[a], end_color[b]);
	std::swap(velocity[a], velocity[b]);
	std::swap(acceleration[a], acceleration[b]);
	std::swap(alive_max[a], alive_max[b]);
	std::swap(alive_time[a], alive_time[b]);
	std::swap(alive[a], alive[b]);
}
