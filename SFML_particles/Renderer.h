#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "ParticleData.h"

class Renderer
{
public:
	virtual void render(sf::RenderTarget& target, const ParticleData& particles) = 0;
};


// TODO: maybe a strategy instead?
class PointRenderer : public Renderer
{
public:
	void render(sf::RenderTarget& target, const ParticleData& particles) override;

};

class LineRenderer : public Renderer
{
public:
	void render(sf::RenderTarget& target, const ParticleData& particles) override;

};
class TriangleRenderer : public Renderer
{
public:
	void render(sf::RenderTarget& target, const ParticleData& particles) override;

};
class QuadRenderer : public Renderer
{
public:
	void render(sf::RenderTarget& target, const ParticleData& particles) override;

};