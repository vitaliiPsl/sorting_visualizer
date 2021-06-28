#include "include/draw.hpp"
#include <iostream>

Draw::Draw(sf::RenderWindow& win) : m_win(win){}

std::vector<sf::RectangleShape> Draw::build_bars(std::vector<float>& data){
    float bar_w = static_cast<float>(m_win.getSize().x / data.size());

    std::vector<sf::RectangleShape> bars_vector(data.size());
    for(int i{}; i < data.size(); i++){
        float bar_h = data[i];

        sf::RectangleShape bar(sf::Vector2f(bar_w, bar_h));
        bar.setFillColor(sf::Color(222, 215, 215));
        bar.setOutlineThickness(bar_w * 0.05);
        bar.setOutlineColor(sf::Color::Black);
        bar.setPosition(i * bar_w, m_win.getSize().y - bar_h);

        bars_vector[i] = bar;
    }

    return bars_vector;
}

void Draw::draw_data(std::vector<float>& data){
    m_win.clear(sf::Color::Black);
    events();

    auto bars = build_bars(data);
    
    for(auto el:bars)
        m_win.draw(el);
    
    m_win.display();
    sf::sleep(sf::milliseconds(1));    
}

void Draw::draw_sort(std::vector<float>& data, int i, int j){
    m_win.clear(sf::Color::Black);
    events();

    auto bars = build_bars(data);
    bars[i].setFillColor(sf::Color::Green);
    bars[j].setFillColor(sf::Color::Red);

    for(auto el:bars)
        m_win.draw(el);
    
    m_win.display();
    sf::sleep(sf::milliseconds(1));
}

void Draw::draw_sort(std::vector<float>& data, int i, int j, int k){
    m_win.clear(sf::Color::Black);
    events();

    auto bars = build_bars(data);
    bars[i].setFillColor(sf::Color::Green);
    bars[j].setFillColor(sf::Color::Red);
    bars[k].setFillColor(sf::Color::Blue);

    for(auto el:bars)
        m_win.draw(el);
    
    m_win.display();
    sf::sleep(sf::milliseconds(1));
}

void Draw::draw_sorted(std::vector<float>& data){
    m_win.clear(sf::Color::Black);
    events();

    auto bars = build_bars(data);
    draw_data(data);
    for(auto el:bars){
        el.setFillColor(sf::Color::Green);
        m_win.draw(el);
        m_win.display();
        sf::sleep(sf::milliseconds(3));
    }
    m_win.display();
}


void Draw::draw_shuffle(std::vector<float>& data, int i, int j){
    m_win.clear(sf::Color::Black);
    events();


    auto bars = build_bars(data);
    bars[i].setFillColor(sf::Color::Green);
    bars[j].setFillColor(sf::Color::Red);

    for(auto el:bars)
        m_win.draw(el);
    
    m_win.display();
    sf::sleep(sf::milliseconds(1));
}

void Draw::draw_menu(){
    m_win.clear(sf::Color::Black);
    events();

    sf::Font f_roboto;
    if(!f_roboto.loadFromFile("./src/font/roboto_bi.ttf")){
        std::cout << "Fonts error. Couldn't load font" << std::endl;
        exit(1);
    }

    sf::Text title;
    
    title.setString("Visualizer");
    title.setFont(f_roboto);
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setOrigin(
        (title.getLocalBounds().left + title.getLocalBounds().width) / 2, 
        (title.getLocalBounds().top - title.getLocalBounds().height) / 2
    );
    // title.setLetterSpacing(title.getCharacterSize() * 0.7);
    title.setPosition(m_win.getSize().x / 2, title.getCharacterSize() + 10);
    
    m_win.draw(title);
    
    sf::Font f_roboto_r;
    if(!f_roboto.loadFromFile("./src/font/roboto_r.ttf")){
        std::cout << "Fonts error. Couldn't load font" << std::endl;
        exit(1);
    }

    std::vector<sf::Text> text(7);

    text[0].setString("Press key:");
    text[1].setString("[B] - Buble sort");
    text[2].setString("[I] - Insertion sort");
    text[3].setString("[M] - Merge sort");
    text[4].setString("[S] - Selection sort");
    text[5].setString("[Space] - Shuffle");
    text[6].setString("[Esc] - Exit");

    for(int i = 0; i < text.size(); i++){
        text[i].setFont(f_roboto);
        text[i].setCharacterSize(m_win.getSize().y / 4 / text.size());
        text[i].setFillColor(sf::Color::White);
        text[i].setLineSpacing(20);
        text[i].setPosition(m_win.getSize().x / 2.5, m_win.getSize().y / 3 + i * text[i].getCharacterSize());
    }
    
    
    
    
    for(auto el:text)
        m_win.draw(el);
            
    m_win.display();
}

void Draw::events(){
    sf::Event event;
    while(m_win.pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            m_win.close();
            exit(1);
        default:
            break;
        }
    }
}