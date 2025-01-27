#include "tools/input_parser.h"

int which_type(string data_type){
    if (data_type == "int") return 1;
    if (data_type == "float") return 2;
    if (data_type == "double") return 3;
    if (data_type == "char") return 4;
    if (data_type == "string") return 5;
    return 0;
}

int which_algo(string algo_name){
    if (algo_name == "selection") return 1;
    if (algo_name == "stupide") return 2;
    if (algo_name == "insertion") return 3;
    if (algo_name == "rapide") return 4;
    return 0;
}