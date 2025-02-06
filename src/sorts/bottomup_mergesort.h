#pragma once

#include <vector>
#include <algorithm>

#include "sorts/probe.h"
#include "tools/swap.h"

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
void bottomup_mergesort(vector<T> &vec, bool reversed=false){
    vector<T> buffer(vec.size()); // on crée un buffer de la taille de vec.
    size_t n = vec.size();
    for (size_t width = 1; width < n; width *= 2){
        for (size_t i = 0; i < n; i += 2 * width){
            bottomup_merge(vec, i, min(i + width, n), min(i + 2 * width, n), buffer);
        }
        copy(buffer.begin(), buffer.end(), vec.begin());
    }
}