#pragma once

#include <vector>
#include "sorts/probe.h"

using namespace std;

/**
 * Permutte deux éléments d'un vecteur, 
 * 
 * @param vec un vecteur
 * 
 * @param i un indice
 * @param j un indice
 * 
 * @ensures si i et j étaient strictement inférieurs à vec.size(),
 * alors, les éléments d'indices i et j ont été permutté
 * @ensures la variable globale __SWAP_COUNT__ est incrémentée de 1
 */
template <typename T> void probed_swap(vector<T> &vec, size_t i, size_t j){
    if (vec.size() - 1 < i || vec.size() < j - 1) return;
    __SWAP_COUNT__++;
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}