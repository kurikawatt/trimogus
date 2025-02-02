#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"

using namespace std;

template <typename T>
void bubblesort(vector<T> &vec, bool reversed=false){
    for (size_t i = 0; i < vec.size()-1; i++){
        for (size_t j = 0; j < vec.size()-i-1; j++){
            __COMPARISION_COUNT__++;
            if ((reversed && vec[j] < vec[j+1]) || (!reversed && vec[j] > vec[j+1])){
                probed_swap(vec, j, j+1);
            }
        }
    }
}

template <typename T>
void optimized_bubblesort(vector<T> &vec, bool reversed=false) {
    bool swapped;
    for (size_t i = 0; i < vec.size()-1; i++) {
        swapped = false;
        for (size_t j = 0; j < vec.size()-i-1; j++) {
            __COMPARISION_COUNT__++;
            if ((reversed && vec[j] < vec[j+1]) || (!reversed && vec[j] > vec[j+1])) {
                probed_swap(vec, j, j+1);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}