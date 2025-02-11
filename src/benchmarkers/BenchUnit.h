#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

#include <nlohmann/json.hpp>

#include "sorts/sorts.h"
#include "generators/numbers.h"
#include "tools/checkers.h"
#include "tools/printers.h"

using namespace std;
using namespace std::chrono;

const vector<int> __VEC_SIZES__ = {10,50,100,500,1000,5000,10000,50000}; 

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
        string get_sort_name();
        nlohmann::json dirty_run(); // plz don't print that to user...
};

template <>
BenchUnit<int>::BenchUnit(string sort_name, void (*sort)(vector<int>&, bool)){
    this->sort_name = sort_name;
    this->sort = sort;
}

template <typename T>
string BenchUnit<T>::get_sort_name(){
    return this->sort_name;
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
nlohmann::json BenchUnit<int>::dirty_run(){ // i repeat, don't use that
    
    vector<int64_t> times_ms = {};
    vector<int64_t> times_s = {};
    vector<long long int> comps = {};
    vector<long long int> swaps = {};
    vector<long long int> buffers_elements_count = {};
    vector<long long int> input_bytes_sizes = {};
    vector<long long int> buffers_bytes_allocated = {};

    cout << this->sort_name << endl;

    for (int i : __VEC_SIZES__){

        __reset_probes();

        vector<int> v = random_int_vector(i);
        
        auto start = high_resolution_clock::now();
        this->sort(v, false);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto duration_s = duration_cast<seconds>(end - start);

        times_ms.push_back(duration.count());
        times_s.push_back(duration_s.count());
        swaps.push_back(__SWAP_COUNT__);
        comps.push_back(__COMPARISION_COUNT__);
        buffers_elements_count.push_back(__BUFFER_SIZE__);
        input_bytes_sizes.push_back(i * sizeof(int));
        buffers_bytes_allocated.push_back(__BYTES_ALLOCATED__);

    }

    nlohmann::json results;
    
    results["datatype"] = "int";
    results["sizes"] = __VEC_SIZES__;
    results["times"]["ms"] = times_ms;
    results["times"]["s"] = times_s;
    results["swaps"] = swaps;
    results["comps"] = comps;
    results["buffers_element_count"] = buffers_elements_count;
    results["memory"]["input"] = input_bytes_sizes;
    results["memory"]["allocated"] = buffers_bytes_allocated;

    return results;

} // r u bored enough to read my shitty comments ?