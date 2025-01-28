#pragma once

#include <vector>
#include "tools/swap.h"

template <typename T>
void selection_sort(vector<T> &vec){

    // Sonde pour le nombre de comp.
    __COMPARISION_COUNT__ = 0;
    // Remise à zéro du compteur de swap.
    __SWAP_COUNT__ = 0;

    int min_index;
    for (int i = 0; i < vec.size()-1; i++){
        min_index = i;
        for (int j = i+1; j < vec.size(); j++){
            __COMPARISION_COUNT__++;
            if (vec[j] < vec[min_index]){
                min_index = j;
            }
        }
        if (i != min_index){
            swap(vec, i, min_index);
        }
    }
};