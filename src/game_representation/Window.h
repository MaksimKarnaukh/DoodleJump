// Author: Maksim Karnaukh
// Implemented as a singleton class.
// Sources :
// Raimondas Pupius, "SFML Game Development By Example", published by Packt Publishing Ltd., ISBN 978-1-78528-734-3
// https://www.sfml-dev.org/tutorials/2.5/window-events.php (pausing the game)

#ifndef DOODLEJUMP_WINDOW_H
#define DOODLEJUMP_WINDOW_H

#include "../logic_library/Stopwatch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <thread>

namespace representation {

class Window
{

        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;

        bool m_isDone;

public:
        static Window& Instance();

        Window(const Window&) = delete;
        Window(const Window&&) = delete;

        Window& operator=(const Window&) = delete;
        Window& operator=(const Window&&) = delete;

public:
        /**
         * @function : Window
         * Constructor for a background Window.
         */
        Window();

        /**
         * @function : Window
         * Constructor for a Window.
         * @param l_title (std::string) : window title
         * @param l_size (sf::Vector2u) : window size
         */
        Window(const std::string& l_title, const sf::Vector2u& l_size);

        /**
         * @function : Window
         * Destructor for a background Window.
         */
        ~Window();

        /**
         * @function : BeginDraw
         * Clears the window.
         */
        void BeginDraw();

        /**
         * @function : EndDraw
         * Displays the changes to the window.
         */
        void EndDraw();

        /**
         * @function : Update
         * Update the window events.
         */
        void Update();

        /**
         * @function : IsDone
         * Checks if the window is closed.
         * @return (bool) : true if the window is closed, false otherwise.
         */
        bool IsDone();

        /**
         * @function : GetWindowSize
         * Returns the size of the window.
         * @return (sf::Vector2u) : a list containing the width and height of the window.
         */
        sf::Vector2u GetWindowSize();

        /**
         * @function : Draw
         * Draws the drawable on the window.
         * @param l_drawable (sf::Drawable) : object that we want to draw.
         */
        void Draw(sf::Drawable& l_drawable);

        /**
         * @function : Draw
         * Setup for the window.
         * @param l_title (std::string) : window title
         * @param l_size (sf::Vector2u) : window size
         */
        void Setup(const std::string& l_title, const sf::Vector2u& l_size);

        /**
         * @function : Destroy
         * Closes the window.
         */
        void Destroy();

        /**
         * @function : Create
         * Opens the window.
         */
        void Create();
};

} // namespace representation

#endif // DOODLEJUMP_WINDOW_H
