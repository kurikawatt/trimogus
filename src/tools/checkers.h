#pragma once

#include <vector>

using namespace std;

/**
 * Vérifie si un vecteur est trié
 * 
 * @param vec un vecteur de type T
 * @param reversed si false, vérifie que le vecteur est trié dans l'ordre croissant
 *                 sinon, vérifie que le vecteur est trié dans l'ordre décroissant
 * @return true si trié, false sinon
 */
template <typename T>
bool is_vector_sorted(vector<T> vec, bool reversed=false){
    for (int i = 0; i < vec.size() - 1; i++){
        if (
            (!reversed && (vec[i] > vec[i+1])) // Vérification de l'ordre croissant
            || (reversed && (vec[i] < vec[i+1])) // Vérification de l'ordre décroissant
        ){
            return false;
        }
    }
    return true;
};