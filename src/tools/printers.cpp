#include "tools/printers.h"

template <typename T> 
void print_array(T arr[], size_t size, string separator){
    for (int i = 0; i < size; i++){
        cout << arr[i] << separator;
    }
    cout << endl;
};

template <typename T> 
void print_vector(vector<T> vec, string separator){
    for (T element : vec){
        cout << element << separator;
    }
    cout << endl;
};

// Un fix qui fonctionne, me demandez pas comment
template void print_array<int>(int arr[], size_t size, string separator);
template void print_vector<int>(vector<int> vec, string separator);