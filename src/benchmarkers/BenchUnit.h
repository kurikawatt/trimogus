#pragma once

#include <iostream>
#include <vector>

#include "sorts/sorts.h"
#include "generators/numbers.h"
#include <functional>

using namespace std;

template <typename T>
class BenchUnit {
    private:
        void (*sort)(vector<T>&);
        size_t max_size;

    public:
        /**
         * Constructeur
         */
        BenchUnit(void (*sort)(vector<T>&), size_t max_vector_size);
        /**
         * Destructeur
         */
        ~BenchUnit()
        {
            return;
        }

        void run();
};

template <>
BenchUnit<int>::BenchUnit(void (*sort)(vector<int>&), size_t max_vector_size){
    this->sort = sort;
    this->max_size = max_vector_size;
}

template <>
void BenchUnit<int>::run(){
    for (int i = 16; i < this->max_size; i = i * 2) {
        cout << "Test pour n=" << i << endl;
        vector<int> v = random_int_vector(i);
        this->sort(v);
    }
}