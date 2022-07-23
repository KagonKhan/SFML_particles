#include "Emitter.h"
#include <iostream>
#include <ctime>
Emitter::Emitter(sf::Vector2f& mouse_pos)
	: mouse_position{mouse_pos}
{

	srand(time(NULL));




}

void Emitter::processEvents(const sf::Event& sf_event)
{

}

void Emitter::update(const sf::Clock &deltaClock)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int i = 0; i < 1; ++i) {
			particles.generate(GENERATE_AMOUNT);
			for (int i = 0; i < particles.count; ++i) {
				float angle{ (float)(rand() % 360) };
				particles.pixels[i].position = sf::Vector2f{ (float)(rand() % 1920), (float)(rand() % 1080) };
				particles.pixels[i].color = colors[rand() % colors.size()];
				particles.dir[i] = sf::Vector2f{ std::cosf(angle), std::sinf(angle) };
			}
		}
	}

	const auto speed{ 5000.f * deltaClock.getElapsedTime().asSeconds() };
	for (int i = 0; i < particles.count; ++i) {
		particles.pixels[i].position += particles.dir[i] * speed;
	}
}

void Emitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (particles.count == 0) return;

	const size_t batch_count{ 100 };
	const size_t batch_size{ GENERATE_AMOUNT / batch_count };
	sf::VertexArray pixels{ sf::Points, batch_size };

	for (int batch = 0; batch < batch_count; ++batch) {
		for (int p = 0; p < batch_size; ++p) {
			pixels[p] = particles.pixels[batch*batch_size + p];
		}
		target.draw(pixels);
	}
	
}

