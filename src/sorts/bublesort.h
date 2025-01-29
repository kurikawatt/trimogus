#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"

using namespace std;

template <typename T>
void bublesort(vector<T> &vec, bool reversed=false){
    if (vec.size() < 2) return;
    for (int i = 0; i < vec.size()-1; i++){
        for (int j = 0; j < vec.size()-i-1; j++){
            __COMPARISION_COUNT__++;
            if ((reversed && vec[j] < vec[j+1]) || (!reversed && vec[j] > vec[j+1])){
                probed_swap(vec, vec[j], vec[j+1]);
            }
        }
    }
}