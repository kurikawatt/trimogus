#pragma once

#include <vector>
#include "sorts/probe.h"

using namespace std;

template <typename T>
vector<T> probed_vec_buffering(size_t buffer_size){
    __BYTES_ALLOCATED__ += buffer_size * sizeof(T);
    __BUFFER_SIZE__ += buffer_size;
    return vector<T>(buffer_size);
}