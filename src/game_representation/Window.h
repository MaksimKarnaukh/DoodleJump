//
// Created by centu on 18/11/2021.
//

#ifndef DOODLEJUMP_WINDOW_H
#define DOODLEJUMP_WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

namespace representation {

    class Window {

        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;

        bool m_isDone;
        bool m_isFullscreen;

        static Window& sInstance; // zelfde structuur als bij stopwatch klasse (singleton)

    public:

        static Window& Instance();

        Window(const Window &) = delete;
        Window(const Window &&) = delete;

        Window& operator=(const Window &) = delete;
        Window& operator=(const Window &&) = delete;

        Window();
        Window(const std::string& l_title,const sf::Vector2u& l_size);
        ~Window();

        void BeginDraw(); // Clear the window.
        void EndDraw(); // Display the changes.

        void Update();
        bool IsDone();
        bool IsFullscreen();
        sf::Vector2u GetWindowSize();
        void ToggleFullscreen();
        void Draw(sf::Drawable& l_drawable);

        void Setup(const std::string& l_title, const sf::Vector2u& l_size);
        void Destroy();
        void Create();

    };

}



#endif //DOODLEJUMP_WINDOW_H
