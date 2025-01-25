#pragma once

#include <vector>

#include "tools/shufflers.h"
#include "tools/checkers.h"

using namespace std;

template <typename T>
void bogosort(vector<T> vec, bool reversed=false){
    while (!is_vector_sorted(vec, reversed)){
        knuth_shuffle(vec);
    }
}