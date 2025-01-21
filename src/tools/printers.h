#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T> 
void print_array(T arr[], size_t size, string separator=" ");

template <typename T> 
void print_vector(vector<T> vec, string separator=" ");