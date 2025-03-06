#pragma once

#include <vector>
#include <algorithm> // for std::max_element

#include "sorts/sorts.h"

template <typename T>
T max_in_vector(const std::vector<T>& vec) {
    T maximum = vec[0];
    for (T e : vec){
        if (e > maximum) maximum = e;
    }
    return maximum;
}

template <typename T>
unsigned int which_bucket(T element, size_t bucket_count, T maximum) {
    return static_cast<unsigned int>((bucket_count * element) / (maximum + 1)); // +1 to avoid division by zero
}

template <typename T>
void buckets_to_vector(const std::vector<std::vector<T>>& buckets, std::vector<T>& vec) {
    size_t i = 0;
    for (const std::vector<T> bucket : buckets) {
        for (const T v : bucket) {
            vec[i++] = v;
        }
    }
}

template <typename T>
std::vector<std::vector<T>> create_buckets(size_t bucket_count) {
    return std::vector<std::vector<T>>(bucket_count);
}

template <typename T>
void bucketsort(std::vector<T>& vec, unsigned int bucket_count, void (*sort)(std::vector<T>&) = insertion_sort<T>) {
    if (vec.size() <= 1) {
        return;
    }
    std::vector<std::vector<T>> buckets = create_buckets<T>(bucket_count);
    T maximum = max_in_vector(vec);
    for (const T e : vec) {
        unsigned int i = which_bucket(e, bucket_count, maximum);
        buckets[i].push_back(e);
    }
    for (std::vector<T> bucket : buckets) {
        sort(bucket);
    }
    buckets_to_vector(buckets, vec);
}