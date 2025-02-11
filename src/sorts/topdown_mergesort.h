#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"
#include "tools/buffers.h"

using namespace std;

template <typename T>
void td_merge(vector<T> &vec, size_t start, size_t middle, size_t end, vector<T> &buffer){
    size_t i,j;
    i = start;
    j = middle;
    for (size_t k = start; k < end; k++){
        __COMPARISION_COUNT__++;
        if (i < middle && (j >= end || buffer[i] <= buffer[j])){
            vec[k] = buffer[i];
            i++;
        } else {
            vec[k] = buffer[j];
            j++;
        }
    }
}

template <typename T>
void td_splitmerge(vector<T> &vec, size_t start, size_t end, vector<T> &buffer){
    if (end - start <= 1) return;
    size_t middle = (end + start) / 2;
    td_splitmerge(buffer, start, middle, vec);
    td_splitmerge(buffer, middle, end, vec);
    td_merge(vec, start, middle, end, buffer);
}

template <typename T>
void topdown_mergesort(vector<T> &vec){
    vector<T> buffer = probed_vec_buffering<T>(vec.size());
    td_splitmerge(vec, 0, vec.size(), buffer);
}