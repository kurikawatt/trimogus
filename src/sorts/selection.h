#pragma once

#include <vector>
#include "tools/swap.h"

#include "sorts/probe.h"

template <typename T>
void selection_sort(vector<T> &vec, bool reversed){
    int min_index;
    for (int i = 0; i < vec.size()-1; i++){
        min_index = i;
        for (int j = i+1; j < vec.size(); j++){
            __COMPARISION_COUNT__++;
            if ((reversed && vec[j] > vec[min_index]) || (!reversed && vec[j] < vec[min_index])){
                min_index = j;
            }
        }
        if (i != min_index){
            probed_swap(vec, i, min_index);
        }
    }
};