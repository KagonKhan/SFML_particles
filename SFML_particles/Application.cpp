#include "Application.h"

Application::Application(std::string name, sf::Vector2f size)
    : window{ sf::VideoMode(size.x, size.y), name }
{
    window.setFramerateLimit(240);
    ImGui::SFML::Init(window);
}

Application::~Application()
{
    ImGui::SFML::Shutdown();
}

void Application::run()
{
    while (window.isOpen()) {
        window.clear();
        processEvents();
        update();

        ImGui::ShowMetricsWindow();

        render();
    }
}

void Application::processEvents()
{
    sf::Event sf_event;
    while (window.pollEvent(sf_event)) {
        ImGui::SFML::ProcessEvent(window, sf_event);

        if (sf_event.type == sf::Event::Closed) {
            window.close();
        }

        emitter.processEvents(sf_event);
    }
}

void Application::update()
{
    mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    ImGui::SFML::Update(window, deltaClock.restart());

    emitter.update(deltaClock);
}

void Application::render()
{
    window.draw(emitter);

    ImGui::SFML::Render(window);
    window.display();
}
