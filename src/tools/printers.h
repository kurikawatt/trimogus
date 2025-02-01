#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T> 
void print_array(T arr[], size_t size, string separator=" "){
    for (int i = 0; i < size; i++){
        cout << arr[i] << separator;
    }
    cout << endl;
};

template <typename T> 
void print_vector(vector<T> vec, string separator=" "){
    cout << "[";
    for (T element : vec){
        cout << element << separator;
    }
    cout << "]" << endl;
};