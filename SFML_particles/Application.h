#pragma once
#include <string>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "imgui-extended.h"
#include "imgui-SFML.h"


#include "ParticleSystem.h"
class Application
{
public:
	Application(std::string name, sf::Vector2f size);
	~Application();

	void run();


private:
	void processEvents();

	void update();

	void render();

	sf::RenderWindow window;

	sf::Clock deltaClock;

	sf::Vector2f mouse_position;

	ParticleSystem system { mouse_position };
};

