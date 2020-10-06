//
// Created by 马嘉骥 on 2020/9/29.
//

#ifndef FINALTEST_SORTTEST_H
#define FINALTEST_SORTTEST_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <functional>

#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

/*
 * Utility functions
 */
template<size_t SIZE>
void RandListGen(int (&arr)[SIZE], int lower, int upper) {
    default_random_engine randE;
    uniform_int_distribution<int> u(lower, upper);
    randE.seed(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = u(randE);
    }
}

template<size_t SIZE>
void PrintArray(int (&arr)[SIZE]) {
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << "\t\t";
    cout << endl;
}


#endif //FINALTEST_SORTTEST_H
