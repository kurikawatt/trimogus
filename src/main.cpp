#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#include <nlohmann/json.hpp>


#include "benchmarkers/BenchUnit.h"
#include "sorts/sorts.h"

using namespace std;

int main(int argc, char *argv[]){

    int SEED = 195;

    srand(SEED);

    vector<BenchUnit<int>> benchs = {};
    benchs.push_back(BenchUnit<int>("selection_sort", selection_sort));
    benchs.push_back(BenchUnit<int>("bubble_sort", bubblesort));
    benchs.push_back(BenchUnit<int>("quicksort", quick_sort));
    benchs.push_back(BenchUnit<int>("top_down_mergesort", topdown_mergesort));
    benchs.push_back(BenchUnit<int>("bottom_up_mergesort", bottomup_mergesort));
    benchs.push_back(BenchUnit<int>("timsort", tim_sort));

    nlohmann::json results;
    results["seed"] = SEED;

    for (BenchUnit<int> b : benchs){
        results[b.get_sort_name()] = b.dirty_run();
    }

    ofstream file("results.json");
    if (file.is_open()) {
        file << std::setw(4) << results << std::endl;
        file.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return 0;
}