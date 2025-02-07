#pragma once

#include <iostream>
#include <vector>
#include <chrono>

#include "sorts/sorts.h"
#include "generators/numbers.h"
#include "tools/checkers.h"
#include "tools/printers.h"

using namespace std;
using namespace std::chrono;

const vector<int> __VEC_SIZES__ = {10,50,100,500,1000,5000,10000,50000,100000,500000,1000000,5000000}; 

template <typename T>
class BenchUnit {
    private:
        string sort_name;
        void (*sort)(vector<T>&, bool);

    public:
        /**
         * Constructeur
         */
        BenchUnit(string name, void (*sort)(vector<T>&, bool));
        /**
         * Destructeur
         */
        ~BenchUnit()
        {
            return;
        }

        void run();
        void dirty_run(); // plz don't print that to user...
};

template <>
BenchUnit<int>::BenchUnit(string sort_name, void (*sort)(vector<int>&, bool)){
    this->sort_name = sort_name;
    this->sort = sort;
}

template <>
void BenchUnit<int>::run(){
    for (int i : __VEC_SIZES__) {
        cout << "-- Test pour n=" << i << " --" << endl;
        vector<int> v = random_int_vector(i);
        auto start = high_resolution_clock::now();
        this->sort(v, false);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "-> Fait en " << duration.count() << "ms (" << __COMPARISION_COUNT__ << " comp., " 
             << __SWAP_COUNT__ << " swaps)" << endl;
        cout << "-> Est trié ? " << is_vector_sorted(v) << endl;
        cout << endl;
    }
}

template <>
void BenchUnit<int>::dirty_run(){ // i repeat, don't use that
    
    vector<size_t> sizes = {};
    vector<int64_t> times_ms = {};
    vector<int64_t> times_s = {};
    vector<long long int> comps = {};
    vector<long long int> swaps = {};

    cout << this->sort_name << endl;

    for (int i : __VEC_SIZES__){

        __reset_probes();

        vector<int> v = random_int_vector(i);
        
        auto start = high_resolution_clock::now();
        this->sort(v, false);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto duration_s = duration_cast<seconds>(end - start);

        sizes.push_back(i);
        times_ms.push_back(duration.count());
        times_s.push_back(duration_s.count());
        swaps.push_back(__SWAP_COUNT__);
        comps.push_back(__COMPARISION_COUNT__);

    }
    
    cout << "sizes=";
    print_vector(sizes, ",");
    cout << "times_ms=";
    print_vector(times_ms, ",");
    cout << "times_s=";
    print_vector(times_s, ",");
    cout << "swaps=";
    print_vector(swaps, ",");
    cout << "comps=";
    print_vector(comps, ",");

} // r u bored enough to read my shitty comments ?