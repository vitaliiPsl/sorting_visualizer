#include "include/visualizer.hpp"

Visualizer::Visualizer(size_t width, size_t height) : m_window(sf::VideoMode(width, height),
"Visualizer", sf::Style::Close | sf::Style::Titlebar), m_draw(m_window){

    m_data.resize(m_window.getSize().x / 7);
    float step = static_cast<float>(m_window.getSize().y) * 0.7 / m_data.size();
    float tmp = 0;
    for(int i{}; i < m_data.size(); i++){
        m_data[i] = tmp;
        tmp += step;
    }
}

void Visualizer::run(){
    while(m_window.isOpen()){
        m_window.clear(sf::Color::Black);
        m_draw.events();
        shuffle();
        menu();
    }
}
void Visualizer::menu(){
    m_draw.draw_menu();

    while(true){
        m_draw.events();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)){
            m_sort = std::make_unique<Insertion>();
            break;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)){
            m_sort = std::make_unique<Buble>();
            break;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            m_sort = std::make_unique<Selection>();
            break;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)){
            m_sort = std::make_unique<Merge>();
            break;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
            m_sort = std::make_unique<Quick>();
            break;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
            shuffle(1);
            return;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
            m_window.close();
            exit(1);
        }

    }
    sort();
}
void Visualizer::sort(){
    m_sort->sort(m_data, m_draw);
}

void Visualizer::shuffle(bool draw){
    srand(time(0));
    
    if(draw){
        m_draw.draw_data(m_data);
        sf::sleep(sf::seconds(1));
    }
    
    for(int i{}; i < 5; i++){
        for(int j{}; j < m_data.size(); j++){
            int k = rand() % m_data.size();
            if(draw){
                m_draw.draw_shuffle(m_data, j, k);
                sf::sleep(sf::milliseconds(15));
            }
            std::swap(m_data[j], m_data[k]);
        }
    }
}