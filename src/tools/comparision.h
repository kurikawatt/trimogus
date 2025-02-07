#pragma once

#include "sorts/probe.h"

template <typename T>
bool probed_loweqt(T x, T y){
    __COMPARISION_COUNT__++;
    return x <= y;
}

template <typename T>
bool probed_greeqt(T x, T y){ // Gruiiiik ?
    __COMPARISION_COUNT__++;
    return x >= y;
}