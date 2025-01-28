#pragma once

#include <vector>

using namespace std;

long long int __SWAP_COUNT__ = 0;

template <typename T> void swap(vector<T> &vec, unsigned int i, unsigned int j){
    __SWAP_COUNT__++;
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}