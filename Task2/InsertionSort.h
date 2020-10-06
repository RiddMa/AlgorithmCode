//
// Created by 马嘉骥 on 2020/9/29.
//

#ifndef FINALTEST_INSERTIONSORT_H
#define FINALTEST_INSERTIONSORT_H
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


template<size_t SIZE>
void InsertionSort(int (&arr)[SIZE]) {
    for (int i = 1; i < SIZE; i++) {
        int tmp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}
#endif //FINALTEST_INSERTIONSORT_H
