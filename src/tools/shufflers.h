#pragma once

#include <vector>

#include "generators/numbers.h"
#include "tools/swap.h"

using namespace std;

/**
 * Mélange en place un vecteur, 
 * en utilisant la méthode Knuth (ou Fisher–Yates)
 * 
 * @param vec le vecteur à mélanger
 * 
 * @return /
 * @ensures l'état du vecteur est une permutation possible
 */
template <typename T>
void knuth_shuffle(vector<T> &vec){
    int j;
    for (int i = 0; i < vec.size(); i++){
        j = random_int(0, vec.size()-1);
        if (i != j) probed_swap(vec, i, j);
    }
};