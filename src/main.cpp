#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include "benchmarkers/BenchUnit.h"
#include "sorts/sorts.h"

using namespace std;

int main(int argc, char *argv[]){

    size_t vec_max_size = 600000;

    vector<BenchUnit<int>> benchs = {};
    benchs.push_back(BenchUnit<int>(selection_sort, vec_max_size));
    benchs.push_back(BenchUnit<int>(bubblesort, vec_max_size));
    benchs.push_back(BenchUnit<int>(quick_sort, vec_max_size));

    for (BenchUnit<int> b : benchs){
        b.dirty_run();
    }

    return 0;
}