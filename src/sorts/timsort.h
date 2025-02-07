#pragma once

#include <vector>
#include <algorithm>

#include "tools/buffers.h"

const int RUN = 32;

template <typename T>
void partial_insertion_sort(vector<T>& vec, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        T temp = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > temp) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = temp;
    }
};

template <typename T>
void merge(vector<T>& vec, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    vector<T> left = probed_vec_buffering<T>(len1);
    vector<T> right = probed_vec_buffering<T>(len2);
    
    for (int i = 0; i < len1; i++)
        left[i] = vec[l + i];
    
        for (int i = 0; i < len2; i++)
        right[i] = vec[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            vec[k] = left[i];
            i++;
        } else {
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        vec[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        vec[k] = right[j];
        k++;
        j++;
    }
};

template <typename T>
void tim_sort(vector<T>& vec, bool reversed=false) {
    int n = vec.size();

    for (int i = 0; i < n; i += RUN)
        partial_insertion_sort(vec, i, min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(vec, left, mid, right);
        }
    }
};