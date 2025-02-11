#pragma once

#include <vector>

#include "tools/shufflers.h"
#include "tools/checkers.h"
#include "sorts/probe.h"

using namespace std;

template <typename T>
void bogosort(vector<T> &vec){
    while (!is_vector_sorted(vec)){
        knuth_shuffle(vec);
    }
}