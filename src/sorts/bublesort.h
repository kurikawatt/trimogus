#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"

using namespace std;

template <typename T>
void bublesort(vector<T> &vec, bool reversed=false){
    for (int i = 0; i < vec.size()-1; i++){
        for (int j = 0; j < i-1; j++){
            if (vec[j+1] < vec[j]){
                swap(vec, j, j+1);
            }
        }
    }
}