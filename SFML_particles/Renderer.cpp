#include "Renderer.h"


void PointRenderer::render(sf::RenderTarget& target, const ParticleData& particles)
{
	if (particles.alive_count == 0) return;

	target.draw(&particles.pixels[0], particles.alive_count, sf::Points);
}

void QuadRenderer::render(sf::RenderTarget& target, const ParticleData& particles)
{
	if (particles.alive_count == 0) return;

	target.draw(&particles.pixels[0], particles.alive_count, sf::Lines);
}

void TriangleRenderer::render(sf::RenderTarget& target, const ParticleData& particles)
{
	if (particles.alive_count == 0) return;

	target.draw(&particles.pixels[0], particles.alive_count, sf::Triangles);
}

void LineRenderer::render(sf::RenderTarget& target, const ParticleData& particles)
{
	if (particles.alive_count == 0) return;

	target.draw(&particles.pixels[0], particles.alive_count, sf::Quads);
}
