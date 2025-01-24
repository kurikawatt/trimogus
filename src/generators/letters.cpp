#include "generators/letters.h"

char random_char(){
    return 'a';
}

string random_string(size_t size){
    string s = "";
    for (int i = 0; i < size; i++){
        s += random_char();
    }
    return s;
}

string random_word(vector<string> &words){
    return "random";
}
vector<char> random_char_vector(size_t size){
    vector<char> c;
    for (int i = 0; i < size; i++){
        c.push_back(random_char());
    }
    c.shrink_to_fit();
    return c;
}

vector<string> random_string_vector(size_t size){
    vector<string> c;
    size_t s;
    for (int i = 0; i < size; i++){
        s = 10;
        c.push_back(random_string(s));
    }
    c.shrink_to_fit();
    return c;
}

vector<string> random_string_vector(vector<string> &words, size_t size){
    vector<string> c;
    for (int i = 0; i < size; i++){
        c.push_back(random_word(words));
    }
    c.shrink_to_fit();
    return c;
}