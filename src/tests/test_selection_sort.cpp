#include <iostream>
#include "tools/checkers.h"
#include "tools/printers.h"
#include "sorts/selection.h"

using namespace std;

int main(){

    vector<int> v = {46,9,23,64,1664};

    cout << "Tableau (non trié) : ";
    print_vector(v);
    cout << "- Est-il trié dans l'ordre croissant ? " << is_vector_sorted(v) << endl;
    cout << "- Est-il trié dans l'ordre décroissant ? " << is_vector_sorted(v, true) << endl;

    cout << "> Tri du tableau avec le tri selection..." << endl;
    selection_sort(&v);

    cout << "Tableau (trié) : ";
    print_vector(v);
    cout << "- Est-il trié dans l'ordre croissant ? " << is_vector_sorted(v) << endl;
    cout << "- Est-il trié dans l'ordre décroissant ? " << is_vector_sorted(v, true) << endl;

    return 0;
}