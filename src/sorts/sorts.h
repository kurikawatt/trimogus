#pragma once

/*

    Ce fichier ert à importer tous les algos de tri en
    un seul header.

*/

#include <map>
#include <string>
#include <functional>
#include <vector>

#include "sorts/selection.h"
#include "sorts/bogosort.h"
#include "sorts/insertion.h"
#include "sorts/quicksort.h"
#include "sorts/bublesort.h"
#include "sorts/topdown_mergesort.h"
#include "sorts/bottomup_mergesort.h"
#include "sorts/timsort.h"

inline std::map<std::string, void (*)(vector<int>&)> SORTS_FUNCTIONS = {
    {"tim_sort", tim_sort<int>},
    {"quick_sort", quicksort<int>},
    {"topdown_mergesort", topdown_mergesort<int>},
    {"bottomup_mergesort", bottomup_mergesort<int>},
    //{"bubblesort", bubblesort<int>},
    //{"insertion_sort", insertion_sort<int>},
    //{"selection_sort", selection_sort<int>}
};