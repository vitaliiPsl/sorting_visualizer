#if !defined(VISUALIZER_H)
#define VISUALIZER_H

#include <memory>
#include <vector>
#include "../SFML/Graphics.hpp"
#include "sort.hpp"
#include "draw.hpp"

class Visualizer{
    sf::RenderWindow m_window;
    std::vector<float> m_data;
    std::unique_ptr<Sort> m_sort;
    Draw m_draw;

public:
    Visualizer(size_t width = 800, size_t height = 600);
    void run();
    void menu();
    void sort();
    void shuffle(bool draw = 0);

};

#endif // VISUALIZER_H
