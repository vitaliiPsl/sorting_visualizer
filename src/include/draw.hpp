#if !defined(Draw_H)
#define Draw_H

#include "../SFML/Graphics.hpp"

class Draw{
    sf::RenderWindow& m_win;

public:
    Draw(sf::RenderWindow& win);

    std::vector<sf::RectangleShape> build_bars(std::vector<float>& data);

    void draw_data(std::vector<float>& data);

    void draw_sort(std::vector<float>& data, int i, int j);

    void draw_shuffle(std::vector<float>& data, int i, int j);

    void draw_sorted(std::vector<float>& data);

    void draw_menu();

    void events();
};

#endif // Draw_H
