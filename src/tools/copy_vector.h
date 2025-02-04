#pragma once

#include <vector>

using namespace std;

template <typename T>
vector<T> copy_vector(vector<T> &vec){
    vector<T> copy = {};
    for (T v : vec){
        copy.push_back(v);
    }
    return copy;
}