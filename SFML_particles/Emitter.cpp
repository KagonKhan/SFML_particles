#include "Emitter.h"
#include <iostream>
#include <ctime>
Emitter::Emitter(sf::Vector2f& mouse_pos)
	: mouse_position{mouse_pos}
{
	particles.reserve(10000);
	srand(time(NULL));



	for (int i = 0; i < 100000; ++i) {
		float angle{ (float)(rand() % 360) };
		particles.push_back(Particle{ sf::Vector2f{(float)(rand()%1920), (float)(rand()%1080)}, sf::Vector2f{std::cosf(angle), std::sinf(angle)}});
	}
}

void Emitter::processEvents(const sf::Event& sf_event)
{

}

void Emitter::update(const sf::Clock &deltaClock)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int i = 0; i < 50; ++i) {
			float angle{ (float)(rand() % 360) };
			particles.push_back(Particle{ mouse_position, sf::Vector2f{std::cosf(angle), std::sinf(angle)} });
		}
	}

	std::ranges::for_each(particles, [&](Particle& p) {
		p.position += p.direction * 5000.f * deltaClock.getElapsedTime().asSeconds();
	});
}

void Emitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape pixel{ 1.f , 12U };

	for (auto& particle : particles) {
		pixel.setPosition(particle.position);
		target.draw(pixel);
	}
}

