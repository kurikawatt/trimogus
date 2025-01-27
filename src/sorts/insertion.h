#pragma once

#include <vector>

using namespace std;

template <typename T>
void insertion_sort(vector<T>& tab){
    
    for (size_t i = 0; i < tab.size(); i++){
        T k = tab[i];
        int j = i-1;

        while(j>= 0 && tab[j] >  k){
            tab[j+1] = tab[j];
            j=j-1;
        }

        tab[j+1]= k;
    }
};