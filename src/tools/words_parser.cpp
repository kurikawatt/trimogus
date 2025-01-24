#include "tools/words_parser.h"

vector<string> parse_words_from_file(string path_to_file){

    vector<string> words;

    string line;
    ifstream file("path_to_file");

    while(getline(file, line)){
        words.push_back(line);
    }
    file.close();

    return words;
}