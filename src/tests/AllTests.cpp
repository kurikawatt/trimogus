#include <iostream>

#include "tests/TestUnit.h"

using namespace std;

int main(){

    bool passed = true;
    cout << "Running all tests for Trimogus" << endl;

    // Insert here all TestUnit to run

    if (passed){
        cout << "-> All tests passed! Congrats!" << endl;
    } else {
        cout << "-> At least one test failed!" << endl;
    }

}