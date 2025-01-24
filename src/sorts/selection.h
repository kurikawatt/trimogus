#pragma once

#include <vector>
#include "tools/swap.h"

template <typename T>
void selection_sort(vector<T> vec){
    int min_index;
    for (int i = 0; i < vec.size(); i++){
        min_index = i;
        for (int j = i+1; j < vec.size(); j++){
            if (vec[j] < vec[i]){
                min_index = j;
            }
        }
        if (i != min_index){
            swap(vec, i, min_index);
        }
    }
};