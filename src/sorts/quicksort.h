#pragma once

#include <vector>

using namespace std;

template <typename T>
int partition(vector<T>& arr, int low, int high) {
  
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

template <typename T>
void quick_sort(vector<T>& arr, int low, int high) {
  
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}