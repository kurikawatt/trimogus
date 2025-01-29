#pragma once

#include <iostream>
#include <vector>
#include <chrono>

#include "sorts/sorts.h"
#include "generators/numbers.h"

using namespace std;
using namespace std::chrono;

template <typename T>
class BenchUnit {
    private:
        void (*sort)(vector<T>&, bool);
        size_t max_size;

    public:
        /**
         * Constructeur
         */
        BenchUnit(void (*sort)(vector<T>&, bool), size_t max_vector_size);
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
BenchUnit<int>::BenchUnit(void (*sort)(vector<int>&, bool), size_t max_vector_size){
    this->sort = sort;
    this->max_size = max_vector_size;
}

template <>
void BenchUnit<int>::run(){
    for (int i = 16; i < this->max_size; i = i * 2) {
        cout << "-- Test pour n=" << i << " --" << endl;
        vector<int> v = random_int_vector(i);
        auto start = high_resolution_clock::now();
        this->sort(v, false);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "-> Fait en " << duration.count() << "ms (" << __COMPARISION_COUNT__ << " comp., " 
             << __SWAP_COUNT__ << " swaps)" << endl;
        cout << endl;
    }
}