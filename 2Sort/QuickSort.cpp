//
// Created by 马嘉骥 on 2020/9/29.
//

#include "Header/QuickSort.h"

extern PerfCounter pc;

/*
 * util func, swap two elements
 */
void Swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    pc.MoveInc(1); // move counter++
}

/*
void Select(int *arr, int size, int left, int right, int k) {

}


 * This function takes last element as pivot, places the pivot element
 * at its correct position in sorted array, and places all smaller
 * (smaller than pivot) to left of pivot and all greater elements to right of pivot
 */
long long Partition(int *arr, long long left, long long right) {
    /*
    default_random_engine randE;
    uniform_int_distribution<int> u(left, right);
    randE.seed(time(nullptr));
    int pivot = arr[u(randE)];
    */
    int pivot = arr[right];
    long long i = (left - 1); // Index of smaller element

    for (long long j = left; j <= right - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            Swap(arr[i], arr[j]);
            pc.CountInc(1); // compare counter++
        }
    }
    Swap(arr[i + 1], arr[right]);
    return (i + 1);
}


void QuickSort(int *arr, long long size, long long left, long long right) {
    if (left < right) {
        /* pi is partitioning index, arr[p] is now at right place */
        long long pi = Partition(arr, left, right);
        // 2Sort elements in the 2 partitions
        QuickSort(arr, size, left, pi - 1);
        QuickSort(arr, size, pi + 1, right);
    }
}

  


