#pragma once

#include <vector>
#include "generators/numbers.h"

using namespace std;

template <typename T>
T pick_in_vector(vector<T> &vec){
    int i = random_int(0, vec.size()-1);
    return vec[i];
}