#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <memory>
#include <SFML/Graphics.hpp>

#include "Util/FPSCounter.h"

#include "CellularAutomaton.h"

struct Config;

class Application
{
    public:
        Application(const Config& config);

        template<typename T> 
        void init()
        {
            m_automaton = std::make_unique<T>(*m_pConfig, *this);
        }

        void run();

        const sf::RenderWindow& getWindow() const;

    private:
        void pollEvents();
        void input  (float dt);
        void render ();

        void resetView();

        std::unique_ptr<CellularAutomaton> m_automaton;

        sf::RenderWindow m_window;
        FPSCounter m_fpsCounter;

        sf::Text            m_guiText;
        sf::View            m_view;

        const Config* m_pConfig = nullptr;
        float m_zoom = 1;
};

#endif // APPLICATION_H_INCLUDED
