#include "ParticleSystem.h"
#include "ParticleGenerator.h"

#include <iostream>
ParticleSystem::ParticleSystem(sf::Vector2f& mouse_position, size_t limit)
	: mouse_position(mouse_position)
{
	auto& [particles, emitter] {emitters};
	particles.generate(limit);

	emitter.addGenerator(cwg);
	emitter.addGenerator(tg);
	emitter.addGenerator(cg);
}

void ParticleSystem::processEvents(const sf::Event& sf_event)
{
}

void ParticleSystem::update(const float& dt)
{
	cwg->position = mouse_position;

	auto& [particles, emitter] {emitters};

	updater->update(dt, particles);
	pos_updater->update(dt, particles);
	col_updater->update(dt, particles);


	emitter.emit(dt, particles);

	std::cout << particles.alive_count << "\n";
}

void ParticleSystem::render(sf::RenderTarget& target)
{
	renderer->render(target, emitters.first);

}
