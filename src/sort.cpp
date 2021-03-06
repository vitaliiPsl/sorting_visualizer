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
            sf::sleep(sf::milliseconds(2));
            if(data[j] < data[i]){
                std::swap(data[j], data[i]);
            }
        }
    }
    draw.draw_sorted(data);
    sf::sleep(sf::seconds(1));
}

void Selection::sort(std::vector<float>& data, Draw& draw){
    for(int i{0}; i < data.size(); i++){
        int min = i; 
        
        for(int j = i; j < data.size(); j++){
            draw.draw_sort(data, i, min, j);
            sf::sleep(sf::milliseconds(2));
            if(data[j] < data[min]){
                min = j;
            }
        }
        std::swap(data[i], data[min]);
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

    draw.draw_sort(data, left, right, mid);
    sf::sleep(sf::milliseconds(20));
    merge_sort(data, left, mid, draw);
    
    draw.draw_sort(data, left, right, mid);
    sf::sleep(sf::milliseconds(20));
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
            draw.draw_sort(data, i, k, mid);
            sf::sleep(sf::milliseconds(15));
            data[k++] = v_left[i++];
        }
        else{
            draw.draw_sort(data, i, j, mid);
            sf::sleep(sf::milliseconds(15));
            data[k++] = v_right[j++];
        }
    }   
    
    while(i < s_left){
        draw.draw_sort(data, i, k, mid);
        sf::sleep(sf::milliseconds(15));
        data[k++] = v_left[i++];
    }

    while(j < s_right){
        draw.draw_sort(data, i, j, mid);
        sf::sleep(sf::milliseconds(15));
        data[k++] = v_right[j++];
    }
}


void Quick::sort(std::vector<float>& data, Draw& draw){
    
    quick_sort(data, 0, data.size() - 1, draw);
    draw.draw_sorted(data);
    sf::sleep(sf::seconds(1));
}

void Quick::quick_sort(std::vector<float>& data, int left, int right, Draw& draw){

    if(left >= right)
        return;
    int part = partition(data, left, right, draw);
    
    draw.draw_sort(data, left, part, right);
    sf::sleep(sf::milliseconds(15));
    quick_sort(data, left, part - 1, draw);
    
    draw.draw_sort(data, left, part, right);
    sf::sleep(sf::milliseconds(15));
    quick_sort(data, part + 1, right, draw);
}

int Quick::partition(std::vector<float>& data, int left, int right, Draw& draw){

    int p_ind = left + std::rand() % (right - left);
    int pivot = data[p_ind];
    std::swap(data[p_ind], data[right]);

    int i = left - 1;
    for(int j = left; j < right; j++){
        if(i >= 0){
            draw.draw_sort(data, i, j, right);
            sf::sleep(sf::milliseconds(15));
        }
        
        if(data[j] < pivot){
            std::swap(data[j], data[++i]);
        }
    }

    std::swap(data[i + 1], data[right]);
    return i + 1;
}