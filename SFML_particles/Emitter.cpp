#include "Emitter.h"
#include <iostream>
#include <ctime>



void Emitter::emit(float dt, ParticleData& particles)
{
	const size_t maxNewParticles = static_cast<size_t>(dt * rate);
	const size_t startId = particles.alive_count;
	const size_t endId = std::min(startId + maxNewParticles, particles.count - 1);


	for (auto& gen : particle_generators)
		gen->generate(particles, startId, endId);

	for (int i = startId; i < endId; ++i)
		particles.wake(i);

}

void Emitter::addGenerator(std::shared_ptr<ParticleGenerator> gen)
{
	particle_generators.push_back(std::move(gen));
}

