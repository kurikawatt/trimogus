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
        std::function<void(std::vector<T>&)> sort;
        
        vector<int64_t> duration = {}; // temps en millisecondes
        vector<long long int> comps = {};
        vector<long long int> swaps = {};
        vector<long long int> input_bytes_size = {};
        vector<long long int> buffers_size = {};
        vector<long long int> buffers_bytes_size = {};

    public:
        Benchmark(std::function<void(std::vector<T>&)>);
        ~Benchmark();
        void set_seed(int seed);
        void set_sort(std::function<void(std::vector<T>&)>);
        void run(vector<size_t> sizes={100,500,1000,5000,10000,50000,100000,500000,1000000,5000000}, int range_min=-100, int range_max=100);
        void record(size_t size, int64_t duration);
        nlohmann::json export_results();

};

template <typename T>
Benchmark<T>::Benchmark(std::function<void(std::vector<T>&)>){
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
void Benchmark<T>::set_sort(std::function<void(std::vector<T>&)>){
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
