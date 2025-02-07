#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include "benchmarkers/BenchUnit.h"
#include "sorts/sorts.h"

using namespace std;

int main(int argc, char *argv[]){

    // Setting the seed to an unknown value
    srand(time(NULL));

    size_t vec_max_size = 500000;

    vector<BenchUnit<int>> benchs = {};
    benchs.push_back(BenchUnit<int>("selection sort", selection_sort));
    benchs.push_back(BenchUnit<int>("bubble sort", bubblesort));
    benchs.push_back(BenchUnit<int>("quicksort", quick_sort));
    benchs.push_back(BenchUnit<int>("top down mergesort", topdown_mergesort));
    benchs.push_back(BenchUnit<int>("bottom up mergesort", bottomup_mergesort));
    benchs.push_back(BenchUnit<int>("timesort", tim_sort));

    for (BenchUnit<int> b : benchs){
        b.dirty_run();
    }

    return 0;
}