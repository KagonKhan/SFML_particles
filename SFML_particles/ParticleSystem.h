#pragma once
#include "Emitter.h"
#include "Renderer.h"
#include "ParticleUpdater.h"

class ParticleSystem
{

	std::pair<ParticleData, Emitter> emitters;
	std::shared_ptr<CircleWaveGenerator> cwg = std::make_shared<CircleWaveGenerator>();
	std::shared_ptr<TimeGenerator> tg = std::make_shared<TimeGenerator>();
	std::shared_ptr<ColorGenerator> cg = std::make_shared<ColorGenerator>();

	sf::Vector2f& mouse_position;
	ParticleUpdater* updater{ new TimeUpdater() };
	ParticleUpdater* pos_updater{ new EulerUpdater() };
	ParticleUpdater* col_updater{ new ColorUpdater() };


	Renderer* renderer{ new QuadRenderer() };

public:
	ParticleSystem(sf::Vector2f& mouse_position, size_t limit = 1'000'000);

	void processEvents(const sf::Event& sf_event);

	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

