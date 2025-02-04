#include "generators/numbers.h"

int random_int(int a, int b){
    return rand() % (b - a + 1) + a;
}

float random_float(float a, float b){
    return (float) rand() / RAND_MAX * (b - a) + a;
}

double random_double(double a, double b){
    return (double) rand() / RAND_MAX * (b - a) + a;
}

vector<int> random_int_vector(size_t size, int a, int b){
    vector<int> v;
    for(int i = 0; i < size; i++){
        v.push_back(random_int(a,b));
    }
	v.shrink_to_fit();
    return v;
}

vector<float> random_float_vector(size_t size, float a, float b){
    vector<float> v;
    for(int i = 0; i < size; i++){
        v.push_back(random_float(a,b));
    }
	v.shrink_to_fit();
    return v;
}

vector<double> random_double_vector(size_t size, double a, double b){
    vector<double> v;
    for(int i = 0; i < size; i++){
        v.push_back(random_double(a,b));
    }
	v.shrink_to_fit();
    return v;
}

vector<int> random_int_vector_controlled(size_t size, float proc){
    vector<int> v;
	
	for(int i = 0; i < size; i++){
		v.push_back(i);
	}

	for(int i = 0; i < size-1; i++){
		float rng = random_float(0,1);
		if(rng < proc){
			int index = random_int(i, size-1);
			swap(v[i], v[index]);
		}
	}

	v.shrink_to_fit();
	return v;
}

vector<float> random_float_vector_controlled(size_t size, float proc){
    vector<float> v;
	
	for(int i = 0; i < size; i++){
		v.push_back((float) i);
	}

	for(int i = 0; i < size-1; i++){
		float rng = random_float(0,1);
		if(rng < proc){
			int index = random_int(i, size-1);
			swap(v[i], v[index]);
		}
	}

	v.shrink_to_fit();
	return v;
}

vector<double> random_double_vector_controlled(size_t size, float proc){
    vector<double> v;
	
	for(int i = 0; i < size; i++){
		v.push_back((double) i); 
	}

	for(int i = 0; i < size-1; i++){
		float rng = random_float(0,1);
		if(rng < proc){
			int index = random_int(i, size-1);
			swap(v[i], v[index]);
		}
	}

	v.shrink_to_fit();
	return v;
}


