#pragma once
#include <vector>
#include "ParticleGenerator.h"


class Emitter
{
public:
	void emit(float dt, ParticleData& particles);

	void addGenerator(std::shared_ptr<ParticleGenerator> gen);


	float rate{ 250'000 };

	std::vector<std::shared_ptr<ParticleGenerator>> particle_generators;
};

