#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#include <nlohmann/json.hpp>

#include "benchmarkers/Benchmark.h"
#include "sorts/sorts.h"

using namespace std;

int main(int argc, char *argv[]){

    int SEED = 195;

    nlohmann::json results;
    results["seed"] = SEED;

    for (const auto& [name, sort] : SORTS_FUNCTIONS){
        cout << "Running benchmark for " << name << "..." << endl;
        Benchmark<int> b(sort);
        b.set_seed(SEED);
        b.run();
        results[name] = b.export_results();
    }

    ofstream file("results.json");
    if (file.is_open()) {
        file << results.dump() << std::endl;
        file.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return 0;
}