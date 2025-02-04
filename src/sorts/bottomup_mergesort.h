#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"
#include "tools/copy_vector.h"

template <typename T>
void bottomup_merge(vector<T> &vec, size_t left, size_t right, size_t end, vector<T> &buffer){
    size_t i,j;
    i = left;
    j = right;
    for (size_t k = left; k < end; k++){
        if (i < right && (j >= end || vec[i] <= vec[j])){
            buffer[k] = vec[i];
            i++;
        } else {
            buffer[k] = vec[j];
            j++;
        }
    }
}

template <typename T>
void bottomup_mergesort(vector<T> &vec){
    vector<T> buffer = copy_vector(vec);
    size_t n = vec.size();
    for (size_t width = 1; width < n; width = width * 2){
        for (size_t i = i; i < n; i = i + width * 2){
            bottomup_merge(vec, i, min(i+width, n), min(i+width*2,n), buffer);
        }
    }
}