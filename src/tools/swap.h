#pragma once

#include <vector>

using namespace std;

template <typename T> void swap(vector<T> vec, unsigned int i, unsigned int j){
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
} 