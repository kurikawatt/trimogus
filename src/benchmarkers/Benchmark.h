#pragma once

#include <string>
#include <vector>
#include <chrono>

#include <nlohmann/json.hpp>

#include "sorts/probe.h"
#include "generators/numbers.h"

using namespace std;
using namespace std::chrono;

template <typename T>
class Benchmark {
    private:
        int seed;
        void (*sort)(vector<T> &vec);

        nlohmann::json summary;
        
        vector<int64_t> duration = {}; // temps en millisecondes
        vector<long long int> comps = {};
        vector<long long int> swaps = {};
        vector<long long int> input_bytes_size = {};
        vector<long long int> buffers_size = {};
        vector<long long int> buffers_bytes_size = {};

    public:
        Benchmark(void (*sort)(vector<T> &vec));
        ~Benchmark();
        void set_seed(int seed);
        void set_sort(void (*sort)(vector<T> &vec));
        void run(vector<size_t> sizes={1000,5000,10000,50000,100000,500000,1000000,5000000,10000000,50000000}, int range_min=-1024, int range_max=1024);
        void record(size_t size, int64_t duration);
        nlohmann::json export_results();
        void reset_value();
        nlohmann::json get_summary();

};

template <typename T>
Benchmark<T>::Benchmark(void (*sort)(vector<T> &vec)){
    this->sort = sort;
    this->seed = time(NULL);
}

template <typename T>
Benchmark<T>::~Benchmark(){}

template <typename T>
void Benchmark<T>::set_seed(int seed){
    this->seed = seed;
}

template <typename T>
void Benchmark<T>::set_sort(void (*sort)(vector<T> &vec)){
    this->sort = sort;
}

template <typename T>
void Benchmark<T>::record(size_t size, int64_t duration){
    this->duration.push_back(duration);
    this->input_bytes_size.push_back(size * sizeof(T));
    this->swaps.push_back(__SWAP_COUNT__);
    this->comps.push_back(__COMPARISION_COUNT__);
    this->buffers_size.push_back(__BUFFER_SIZE__);
    this->buffers_bytes_size.push_back(__BYTES_ALLOCATED__);
}

template <>
void Benchmark<int>::run(vector<size_t> sizes, int range_min, int range_max){
    for (size_t n : sizes){
        cout << "- fully random of " << n << " elements" << endl;
        // On reset la seed à chaque tour, pour que les tableaux soient toujours identique
        srand(this->seed);
        // Idem pour les sondes, afin de ne pas fausser les résultats
        __reset_probes();

        vector<int> vec = random_int_vector(n, range_min, range_max);
        auto start_time = high_resolution_clock::now();

        this->sort(vec);

        auto end_time = high_resolution_clock::now();
        int64_t duration = duration_cast<milliseconds>(end_time - start_time).count();
        this->record(n, duration);
        
    }
    this->summary["random"] = this->export_results();
    this->reset_value();

    for (size_t n : sizes){
        cout << "- half sorted of " << n << " elements" << endl;
        // On reset la seed à chaque tour, pour que les tableaux soient toujours identique
        srand(this->seed);
        // Idem pour les sondes, afin de ne pas fausser les résultats
        __reset_probes();

        vector<int> vec = random_int_vector_controlled(n, 0.5);
        auto start_time = high_resolution_clock::now();

        this->sort(vec);

        auto end_time = high_resolution_clock::now();
        int64_t duration = duration_cast<milliseconds>(end_time - start_time).count();
        this->record(n, duration);
    }
    this->summary["half_sorted"] = this->export_results();
    this->reset_value();
    
    for (size_t n : sizes){
        cout << "- already sorted of " << n << " elements" << endl;
        // On reset la seed à chaque tour, pour que les tableaux soient toujours identique
        srand(this->seed);
        // Idem pour les sondes, afin de ne pas fausser les résultats
        __reset_probes();

        vector<int> vec = random_int_vector_controlled(n, 0);

        auto start_time = high_resolution_clock::now();

        this->sort(vec);

        auto end_time = high_resolution_clock::now();
        int64_t duration = duration_cast<milliseconds>(end_time - start_time).count();
        this->record(n, duration);
    }
    this->summary["sorted"] = this->export_results();
    this->reset_value();

}

template <typename T>
void Benchmark<T>::reset_value(){
    this->duration = {}; // temps en millisecondes
    this->comps = {};
    this->swaps = {};
    this->input_bytes_size = {};
    this->buffers_size = {};
    this->buffers_bytes_size = {};
}

template <typename T>
nlohmann::json Benchmark<T>::export_results(){
    nlohmann::json results;

    results["duration"] = this->duration;
    results["input_bytes_size"] = this->input_bytes_size;
    results["swap"] = this->swaps;
    results["comps"] = this->comps;
    results["buffers"]["size"] = this->buffers_size;
    results["buffers"]["bytes_allocated"] = this->buffers_bytes_size;

    return results;
}

template <typename T>
nlohmann::json Benchmark<T>::get_summary(){
    return this->summary;
}