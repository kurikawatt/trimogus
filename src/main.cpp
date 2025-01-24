#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include "benchmarkers/debug_benchmark.h"
#include "tools/input_parser.h"

using namespace std;

void print_version(){
    cout << "Trimogus InDev" << endl;
}

int main(int argc, char *argv[]){

    int opt;

    string algo_name;
    string data_type;
    string path_to_words_file;
    size_t vec_size = -1;
    unsigned int seed = time(NULL);

    while ( (opt = getopt(argc, argv, "a:n:t:s:f:v")) != -1){
        switch (opt){
            case 'v':
                print_version();
                break;
            case 'a':
                algo_name = optarg;
                break;
            case 't':
                data_type = optarg;
                break;
            case 'n':
                vec_size = atoi(optarg);
                break;
            case 's':
                seed = atoi(optarg);
                break;
            case 'f':
                path_to_words_file = optarg;
                break;
            default:
                break;
        }
    }
    
    if (algo_name.empty() || data_type.empty() || path_to_words_file.empty() || vec_size == -1) {
        cerr << "Erreur: Vous devez fournir des arguments." << endl;
        return 1;
    }

    switch (which_type(data_type))
    {
    case 1:
        bench<int>(which_algo(algo_name), which_type(data_type), vec_size);
        break;
    
    default:
        break;
    }

    return 0;
}