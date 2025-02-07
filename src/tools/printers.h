#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Afficher un tableau dans la sortie standard
 * 
 * @param arr[] un tableau de type T
 * @param size la taille du tableau
 * @requires size >= la taille réelle du tableau
 * @param sperator la chaine de séparation entre deux valeurs
 */
template <typename T> 
void print_array(T arr[], size_t size, string separator=" "){
    for (size_t i = 0; i < size; i++){
        cout << arr[i] << separator;
    }
    cout << endl;
};


/**
 * Afficher un vecteur dans la sortie standard
 * 
 * @param vec un vecteur de type T
 * @param sperator la chaine de séparation entre deux valeurs
 */
template <typename T> 
void print_vector(vector<T> vec, string separator=" "){
    for (T element : vec){
        cout << element << separator;
    }
    cout << endl;
};