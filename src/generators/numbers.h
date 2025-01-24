#pragma once

#include <limits.h>

#include <vector>
#include <cstdlib>

using namespace std;

int random_int(int a=INT_MIN, int b=INT_MAX);

float random_float(float a, float b);

double random_double(double a, double b);

vector<int> random_int_vector(size_t size, int a=INT_MIN, int b=INT_MAX);

vector<float> random_float_vector(size_t size, float a, float b);

vector<double> random_double_vector(size_t size, double a, double b);