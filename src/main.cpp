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

    vector<BenchUnit<int>> benchs = {};
    benchs.push_back(BenchUnit<int>("selection_sort", selection_sort));
    benchs.push_back(BenchUnit<int>("bubble_sort", bubblesort));
    benchs.push_back(BenchUnit<int>("quicksort", quick_sort));
    benchs.push_back(BenchUnit<int>("top_down_mergesort", topdown_mergesort));
    benchs.push_back(BenchUnit<int>("bottom_up_mergesort", bottomup_mergesort));
    benchs.push_back(BenchUnit<int>("timsort", tim_sort));

    for (BenchUnit<int> b : benchs){
        b.dirty_run();
    }

    return 0;
}