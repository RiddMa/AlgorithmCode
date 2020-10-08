//
// Created by 马嘉骥 on 2020/9/29.
//
#undef _HAS_STD_BYTE
#ifndef FINALTEST_SORTTEST_H
#define FINALTEST_SORTTEST_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <functional>
#include <climits>

#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

#ifdef _WIN32
#include <windows.h>
#else

#include <unistd.h>

#endif // _WIN32

/*
 * Utility functions
 */
class PerfCounter {
private:
    long long Count;
    long long Move;
public:
    void CountInc(long long n) {
        Count += n;
    }

    void CountClear() {
        Count = 0;
    }

    long long GetCount() {
        return Count;
    }

    void MoveInc(long long n) {
        Move += n;
    }

    void MoveClear() {
        Move = 0;
    }

    long long GetMove() {
        return Move;
    }
};

#endif //FINALTEST_SORTTEST_H
