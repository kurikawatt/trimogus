#pragma once
#include <cstddef>

#include <vector>
#include <chrono>

#include "generators/generate_vec.h"
#include "tools/printers.h"
#include "sorts/sorts.h"
#include "tools/checkers.h"

using namespace std;
using namespace std::chrono;

template <typename T>
void bench(int algo, int type, size_t size){

	vector<T> v = generate_vector<T>(type, size);
    /*
    cout << "Voici le tableau généré : " << endl;
    print_vector(v);
    */
    auto start = high_resolution_clock::now();
    switch (algo)
    {
    case 1:
        cout << "Application du tri sélection..." << endl;
        selection_sort<T>(v);
        break;
    case 2:
        cout << "Application du tri stupide..." << endl;
        bogosort<T>(v);
        break;
    case 3:
        cout << "Application du tri insertion..." << endl;
        insertion_sort<T>(v);
        break;
    case 4:
        cout << "Application du tri rapide..." << endl;
        quick_sort<T>(v, 0, size);
        break;
    default:
        exit(0);
        break;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    /*
    cout << "Voici le tableau trié : " << endl;
    print_vector(v);
    */
    cout << "-> Taille du tableau: " << size << endl;
    cout << "-> Est-il trié dans l'ordre croissant ? " << is_vector_sorted(v) << endl;
    cout << "-> Temps d'exécution: " << duration.count() << "s" << endl;  
    cout << "-> Nombre de comparaison: " << __COMPARISION_COUNT__ << endl;
    cout << "-> Nombre d'échanges (swap): " << __SWAP_COUNT__ << endl;


}