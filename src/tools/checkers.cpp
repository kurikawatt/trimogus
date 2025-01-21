#include "checkers.h"

template <typename T> bool is_vector_sorted(vector<T> vec, bool reversed){
    for (int i = 0; i < vec.size() - 1; i++){
        if ((!reversed && (vec[i] > vec[i+1])) || (reversed && (vec[i] < vec[i+1]))){
            return false;
        }
    }
    return true;
};