#include <vector>

#include "tests/TestUnit.h"
#include "tools/checkers.h"
#include "generators/numbers.h"

class CheckersTests : TestUnit {

    public:
        bool run_all_tests();
        bool test_ascending();
        bool test_descending();

};

bool CheckersTests::test_ascending(){
    vector<int> sorted = {1,2,3,4,5,6,7,8,9,10};
    vector<int> random = random_int_vector(10, 1, 10);

    bool passed = true;

    passed = passed && is_vector_sorted(sorted);
    passed = passed && !is_vector_sorted(random);

    return passed;
}

bool CheckersTests::test_descending(){
    vector<int> sorted = {10,9,8,7,6,5,4,3,2,1};
    vector<int> random = random_int_vector(10, 1, 10);

    bool passed = true;
    
    passed = passed && is_vector_sorted(sorted, true);
    passed = passed && !is_vector_sorted(random, true);

    return passed;

}

bool CheckersTests::run_all_tests(){
    bool passed = true;
    passed = passed && CheckersTests::test_ascending();
    passed = passed && CheckersTests::test_descending();
    return passed;
}