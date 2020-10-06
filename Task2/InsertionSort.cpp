//
// Created by 马嘉骥 on 2020/9/29.
//

#include "InsertionSort.h"

void InsertionSort(int *arr, long long SIZE) {
    CompareCounter cc;
    for (int i = 1; i < SIZE; i++) {
        int tmp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
            arr[j+1] = arr[j];
            cc.CountInc();
        }
        arr[j+1] = tmp;
    }
}