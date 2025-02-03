#pragma once

#include <vector>
#include "sorts/probe.h"

using namespace std;

template <typename T> void probed_swap(vector<T> &vec, unsigned int i, unsigned int j){
    if (vec.size() < i || vec.size() < j) return;
    __SWAP_COUNT__++;
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}