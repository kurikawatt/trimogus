#pragma once

#include <string>
#include <vector>

using namespace std;

char random_char();

string random_string(size_t size);

string random_word(vector<string> &words);

vector<char> random_char_vector(size_t size);

vector<string> random_string_vector(size_t size);

vector<string> random_words_vector(vector<string> &words, size_t size);