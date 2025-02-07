#pragma once

#include <vector>
#include "generators/numbers.h"

using namespace std;

/**
 * Pioche un élément du vecteur
 * 
 * @param vec le vecteur de type T dans lequel on pioche
 * 
 * @return v de type T
 * @ensures v est une valeur de vec
 */
template <typename T>
T pick_in_vector(vector<T> &vec){
    int i = random_int(0, vec.size()-1);
    return vec[i];
}