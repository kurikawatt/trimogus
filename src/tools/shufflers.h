#pragma once

#include <vector>

#include "generators/numbers.h"
#include "tools/swap.h"

using namespace std;

template <typename T>
void hnuth_shuffle(vector<T> vec){
    int j;
    for (int i = 0; i < vec.size(; i++)){
        j = random_int(0, vec.size()-1);
        if (i != j) swap(vec, i, j);
    }
}