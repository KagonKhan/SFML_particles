#include "Emitter.h"
#include <iostream>
#include <ctime>


#include <execution>



Emitter::Emitter(sf::Vector2f& mouse_pos)
	: mouse_position{ mouse_pos }
{
	srand(time(NULL));
}

void Emitter::processEvents(const sf::Event& sf_event)
{
	if (sf_event.type == sf::Event::MouseButtonPressed) {
		auto speed{ 5000.f };

		particles.emplace_back();
		auto& p = particles.back();
		p.generate(GENERATE_AMOUNT);

		float radius = (float)(rand() % 100);

		for (int i = 0; i < p.count; ++i) {
			float angle{ (float)(rand() % 360000) / 1000.f };
			auto cart_angle = sf::Vector2f{ std::cosf(angle), std::sinf(angle) };

			p.pixels[i].position = mouse_position + cart_angle * radius;
			p.velocity[i] = cart_angle * speed;
		}

	}
}

void Emitter::update(const sf::Clock& deltaClock)
{
	auto dt = deltaClock.getElapsedTime().asSeconds();

	for (auto& p : particles) {
		for (int i = 0; i < p.count; ++i) {
			p.pixels[i].position += p.velocity[i] * dt;
		}
	}
}

void Emitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (particles.empty()) return;

	const size_t batch_count{ 250 };
	const size_t batch_size{ GENERATE_AMOUNT / batch_count };

	for (auto& p : particles) {
		for (int batch = 0; batch < batch_count; ++batch) {
			target.draw(&p.pixels[batch * batch_size], batch_size, sf::Points);
		}
	}
}

