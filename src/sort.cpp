#include "include/sort.hpp"

void Insertion::sort(std::vector<float>& data){
    for(int i{1}; i < data.size(); i++){
        float tmp = data[i];
        int j = i;
        while(j > 0 && data[j-1] > tmp){
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }
}

void Buble::sort(std::vector<float>& data){
    for(int i = 0; i < data.size(); i++){
        for(int j{i}; j < data.size(); j++){
            if(data[j] < data[i]){
                std::swap(data[j], data[i]);
            }
        }
    }
}

void Merge::sort(std::vector<float>& data){
    merge_sort(data, 0, data.size() - 1);
}

void Merge::merge_sort(std::vector<float>& data, int left, int right){
    if(left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(data, left, mid);
    merge_sort(data, mid + 1, right);
    merge(data, left, mid, right);
}

void Merge::merge(std::vector<float>& data, int left, int mid, int right){
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
            data[k++] = v_left[i++];
        }
        else{
            data[k++] = v_right[j++];
        }
    }   
    

    while(i < s_left){
        data[k++] = v_left[i++];
    }

    while(j < s_right){
        data[k++] = v_right[j++];
    }
}