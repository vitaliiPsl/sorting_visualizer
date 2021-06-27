#include "include/sort.hpp"
#include <iostream>

void Insertion::sort(std::vector<float>& data, Draw& draw){
    for(int i{1}; i < data.size(); i++){
        sf::sleep(sf::milliseconds(10));
        float tmp = data[i];
        int j = i;
        draw.draw_sort(data, i, j);
        while(j > 0 && data[j-1] > tmp){
            draw.draw_sort(data, i, j);
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }

    draw.draw_sorted(data);
    sf::sleep(sf::seconds(1));
}

void Buble::sort(std::vector<float>& data, Draw& draw){
    for(int i{0}; i < data.size(); i++){
        for(int j{i}; j < data.size(); j++){
            draw.draw_sort(data, i, j);
            sf::sleep(sf::milliseconds(5));
            if(data[j] < data[i]){
                std::swap(data[j], data[i]);
            }
        }
    }
    draw.draw_sorted(data);
    sf::sleep(sf::seconds(1));
}

void Merge::sort(std::vector<float>& data, Draw& draw){
    merge_sort(data, 0, data.size() - 1, draw);
    draw.draw_sorted(data);
    sf::sleep(sf::seconds(1));
}

void Merge::merge_sort(std::vector<float>& data, int left, int right, Draw& draw){
    if(left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(data, left, mid, draw);
    merge_sort(data, mid + 1, right, draw);
    merge(data, left, mid, right, draw);
}

void Merge::merge(std::vector<float>& data, int left, int mid, int right, Draw& draw){
    int s_left = mid - left + 1;
    int s_right = right - mid;

    std::vector<float> v_left(s_left);
    std::vector<float> v_right(s_right);

    for(int i{}; i < s_left; i++)
        v_left[i] = data[left + i];

    for(int i{}; i < s_right; i++)
        v_right[i] = data[mid + 1 + i];

    int i{}, j{}, k{left};

    while(i < s_left && j < s_right){
        if(v_left[i] < v_right[j]){
            draw.draw_sort(data, i, k);
            sf::sleep(sf::milliseconds(10));
            data[k++] = v_left[i++];
        }
        else{
            draw.draw_sort(data, i, j);
            sf::sleep(sf::milliseconds(10));
            data[k++] = v_right[j++];
        }
    }   
    
    while(i < s_left){
        draw.draw_sort(data, i, k);
        sf::sleep(sf::milliseconds(10));
        data[k++] = v_left[i++];
    }

    while(j < s_right){
        draw.draw_sort(data, i, j);
        sf::sleep(sf::milliseconds(10));
        data[k++] = v_right[j++];
    }
}