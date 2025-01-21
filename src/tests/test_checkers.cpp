#include <iostream>
#include "tools/checkers.h"
#include "tools/printers.h"

using namespace std;

int main(){

    vector<int> sorted_asc = {1,2,3,4,5,6,7,8,9,10};
    vector<int> sorted_dsc = {10,9,8,7,6,5,4,3,2,1};
    vector<int> not_sorted = {46,9,23,64,1664};
    vector<char> letters_sorted = {'a', 'b', 'c', 'd', 'e', 'f'};

    cout << "Premier tableau (trié croissant) : " << endl;
    print_vector(sorted_asc);
    cout << "Est-il trié dans l'ordre croissant ? " << is_vector_sorted(sorted_asc) << endl;
    cout << "Est-il trié dans l'ordre décroissant ? " << is_vector_sorted(sorted_asc, true) << endl;

    cout << "Second tableau (trié décroissant) : " << endl;
    print_vector(sorted_dsc);
    cout << "Est-il trié dans l'ordre croissant ? " << is_vector_sorted(sorted_dsc) << endl;
    cout << "Est-il trié dans l'ordre décroissant ? " << is_vector_sorted(sorted_dsc, true) << endl;

    cout << "Troisième tableau (non trié) : " << endl;
    print_vector(not_sorted);
    cout << "Est-il trié dans l'ordre croissant ? " << is_vector_sorted(not_sorted) << endl;
    cout << "Est-il trié dans l'ordre décroissant ? " << is_vector_sorted(not_sorted, true) << endl;

    cout << "Quatrième tableau (trié croissant) : " << endl;
    print_vector<char>(letters_sorted);
    cout << "Est-il trié dans l'ordre croissant ? " << is_vector_sorted<char>(letters_sorted) << endl;
    cout << "Est-il trié dans l'ordre décroissant ? " << is_vector_sorted<char>(letters_sorted, true) << endl;

    return 0;
}