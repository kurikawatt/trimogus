#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void print_version(){
    cout << "Trimogus InDev" << endl;
}

int main(int argc, char *argv[]){

    int opt;

    string algo_name;
    string data_type;
    string path_to_words_file;
    size_t vec_size;
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
    
    return 0;
}