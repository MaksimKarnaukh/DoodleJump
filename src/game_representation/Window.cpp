//
// Created by centu on 18/11/2021.
//

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

    void Window::Destroy(){
        m_window.close();
    }

    void Window::Update(){
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_isDone = true;
            }
        }
    }

    void Window::BeginDraw(){ m_window.clear(sf::Color::Black); }

    void Window::EndDraw(){ m_window.display(); }

    bool Window::IsDone(){ return m_isDone; }

    sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }

    void Window::Draw(sf::Drawable &l_drawable){
        m_window.draw(l_drawable);
    }



}


