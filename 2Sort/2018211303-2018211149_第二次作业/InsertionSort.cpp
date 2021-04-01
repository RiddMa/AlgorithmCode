//
// Created by 马嘉骥 on 2020/9/29.
//

#include "Header/InsertionSort.h"

extern PerfCounter pc;

void InsertionSort(int *arr, long long SIZE) {
    for (long long i = 1; i < SIZE; i++) {
        int tmp = arr[i];
        long long j;
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
            arr[j + 1] = arr[j];
            pc.CountInc(1);
            pc.MoveInc(1);
        }
        arr[j + 1] = tmp;
    }
}