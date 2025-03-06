#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#include <nlohmann/json.hpp>

#include "benchmarkers/Benchmark.h"
#include "sorts/sorts.h"

#include "generators/numbers.h"
#include "tools/checkers.h"

using namespace std;

int main(int argc, char *argv[]){

    int SEED = 195;

    srand(SEED);

    vector<void (*)(vector<int>&)> sorts = {selection_sort<int>, insertion_sort<int>, bubblesort<int>, tim_sort<int>, topdown_mergesort<int>, bottomup_mergesort<int>};
    vector<string> sorts_names = {"selection", "insertion", "bubblesort", "timsort", "tp_mergesort", "bu_mergesort"};

    vector<int> vec = random_int_vector(50000, -2048, 2048);

    for (int i = 0; i < sorts.size(); i++){
        vector<int> v(vec);
        //cout << "Running " << sorts_names[i] << endl;
        sorts[i](v);
        //cout << "And is it correct ?" << is_vector_sorted(v) << endl;
    }

    return 0;
}