#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#include <nlohmann/json.hpp>
#include <omp.h>

#include "benchmarkers/Benchmark.h"
#include "sorts/sorts.h"

#include "generators/numbers.h"
#include "tools/checkers.h"

using namespace std;

int main(int argc, char *argv[]){

    int SEED = 195;

    srand(SEED);

    vector<void (*)(vector<int>&)> sorts = {tim_sort<int>, topdown_mergesort<int>, bottomup_mergesort<int>};
    vector<string> sorts_names = {"timsort", "tp_mergesort", "bu_mergesort"};

    omp_set_num_threads(3);

    vector<int> vec = random_int_vector(50000000, -2048, 2048);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        vector<int> v(vec);
        cout << "Thread " << tid << " will run " << sorts_names[tid] << endl;
        sorts[tid](v);
        cout << "Thread " << tid << " sort is : " << is_vector_sorted(v) << endl;
    }

    return 0;
}