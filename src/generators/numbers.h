#pragma once

#include <limits.h>

#include <vector>
#include <cstdlib>

#define MIN_INT_GEN -1000000
#define MAX_INT_GEN 1000000

using namespace std;

int random_int(int a=MIN_INT_GEN, int b=MAX_INT_GEN);

float random_float(float a, float b);

double random_double(double a, double b);

vector<int> random_int_vector(size_t size, int a=MIN_INT_GEN, int b=MAX_INT_GEN);

vector<float> random_float_vector(size_t size, float a, float b);

vector<double> random_double_vector(size_t size, double a, double b);

vector<int> genIntTabControlled(size_t size, double proc);