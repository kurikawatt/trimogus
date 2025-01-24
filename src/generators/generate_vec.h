#pragma once

#include <vector>

#include "generators/numbers.h"

using namespace std;

template <typename T>
vector<T> generate_vector(int type, size_t size){
    switch (type){
        case 1:
            return random_int_vector(size);
            break;
        default:
            return {};
            break;
    }
}