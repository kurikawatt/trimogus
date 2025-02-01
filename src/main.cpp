#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include "benchmarkers/BenchUnit.h"
#include "sorts/sorts.h"

using namespace std;

int main(int argc, char *argv[]){
    
    cout << "\t-- Tri sélection --" << endl;
    BenchUnit<int> unit(selection_sort, 70000);
    unit.run();
    cout << "\t-------------------" << endl;
    
    cout << "\t-- Tri à bulle --" << endl;
    BenchUnit<int> unit2(bubblesort, 70000);
    unit2.run();
    cout << "\t-------------------" << endl;
    
    cout << "\t-- Tri rapide --" << endl;
    BenchUnit<int> unit3(quick_sort, 70000);
    unit3.run();
    cout << "\t-------------------" << endl;

    return 0;
}