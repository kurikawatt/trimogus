#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"

using namespace std;

template <typename T>
void quicksort(vector<T> &vec);

template <typename T>
void quicksort_aux(vector<T> &vec, unsigned int low, unsigned int high);

template <typename T>
unsigned int partition(vector<T> &vec, unsigned int low, unsigned int high);

template <typename T>
void quicksort(vector<T> &vec){
    quicksort_aux(vec, 0, vec.size() - 1);
}

template <typename T>
void quicksort_aux(vector<T> &vec, unsigned int low, unsigned int high){
    if (low < high && high < vec.size()){
        unsigned int pi = partition(vec, low, high);
        quicksort_aux(vec, low, pi - 1);
        quicksort_aux(vec, pi + 1, high);
    }
}

template <typename T>
unsigned int partition(vector<T> &vec, unsigned int low, unsigned int high){
    T pivot = vec[high];
    unsigned int i = low - 1;
    for (unsigned int j = low; j < high; j++){
        __COMPARISION_COUNT__++;
        if (vec[j] < pivot){
            i++;
            probed_swap(vec, i, j);
        }
    }
    probed_swap(vec, i + 1, high);
    return i + 1;
}