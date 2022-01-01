// Author: Maksim Karnaukh


#include "Window.h"

namespace representation {

    Window &Window::Instance() {
        static Window instance;
        return instance;
    }

    Window::Window() {
        Setup("Doodle Jump", sf::Vector2u(640,960));
    }

    Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {
        Setup(l_title,l_size);
    }
    Window::~Window() {
        Destroy();
    }

    void Window::Setup(const std::string &l_title, const sf::Vector2u& l_size) {
        m_windowTitle = l_title;
        m_windowSize = l_size;
        m_isDone = false;
        Create();
    }

    void Window::Create(){
        m_window.create({ m_windowSize.x, m_windowSize.y, 32 },m_windowTitle);
    }

    void Window::Destroy() {
        m_window.close();
    }

    void Window::Update() {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_isDone = true;
            }
            if (event.type == sf::Event::LostFocus || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                sf::Event event1;
                while (true) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                    if (m_window.pollEvent(event1) && (event1.type == sf::Event::GainedFocus ||  event1.type == sf::Event::KeyPressed && event1.key.code == sf::Keyboard::Escape)) {
                        logic::utility::Stopwatch::Instance().Reset();
                        break;
                    }
                }
            }

        }
    }

    void Window::BeginDraw() { m_window.clear(sf::Color::Black); }

    void Window::EndDraw() { m_window.display(); }

    bool Window::IsDone() { return m_isDone; }

    sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }

    void Window::Draw(sf::Drawable &l_drawable){
        m_window.draw(l_drawable);
    }



}


