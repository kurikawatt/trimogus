#pragma once
#include <cstddef>

#include <vector>

#include "generators/generate_vec.h"
#include "tools/printers.h"
#include "sorts/selection.h"
#include "tools/checkers.h"

using namespace std;

template <typename T>
void bench(int algo, int type, size_t size){

	vector<T> v = generate_vector<T>(type, size);
    
    cout << "Voici le tableau généré : " << endl;
    print_vector(v);

    switch (algo)
    {
    case 1:
        cout << "Application du tri sélection..." << endl;
        selection_sort(v);
        break;
    
    default:
        break;
    }

    cout << "Voici le tableau trié : " << endl;
    print_vector(v);

    cout << "-> Est-il trié dans l'ordre croissant ? " << is_vector_sorted(v) << endl;

}