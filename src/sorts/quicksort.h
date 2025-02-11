#pragma once

#include <vector>

#include "sorts/probe.h"
#include "tools/swap.h"

using namespace std;

template <typename T>
int partition(vector<T>& arr, int low, int high) {
  
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        __COMPARISION_COUNT__++;
        if (arr[j] < pivot) {
            i++;
            probed_swap(arr, i, j);
        }
    }
    probed_swap(arr, i + 1, high);  
    return i + 1;
}

template <typename T>
void quick_sort_aux(vector<T>& arr, int low, int high) {
  
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_aux(arr, low, pi - 1);
        quick_sort_aux(arr, pi + 1, high);
    }
}

template <typename T>
void quick_sort(vector<T> &vec){
    quick_sort_aux(vec, 0, vec.size());
}