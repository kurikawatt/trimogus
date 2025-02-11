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

void nextWord(string &currWord);

void previousWOrd(string &currWord);

vector<char> random_char_vector_controlled(size_t size, float proc);

vector<string> random_string_vector_controlled(size_t size, float proc);

vector<string> random_word_vector_controlled(size_t size, vector<string> &words, float proc);

vector<char> reversed_sorted_char_vector(size_t size);

vector<string> reversed_sorted_word_vector(size_t size, vector<string> listesMots);

vector<string> reversed_sorted_string_vector(size_t size);