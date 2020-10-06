//
// Created by 马嘉骥 on 2020/9/29.
//

#ifndef FINALTEST_QUICKSORT_H
#define FINALTEST_QUICKSORT_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/*
 * util func, swap two elements
 */
void Swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

template<size_t SIZE>
void Select(int (&arr)[SIZE], int left, int right, int k) {

}

/*
 * This function takes last element as pivot, places the pivot element
 * at its correct position in sorted array, and places all smaller
 * (smaller than pivot) to left of pivot and all greater elements to right of pivot
 */
template<size_t SIZE>

int Partition(int (&arr)[SIZE], int left, int right) {
    int pivot = arr[right]; // pivot
    int i = (left - 1); // Index of smaller element

    for (int j = left; j <= right - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i + 1], arr[right]);
    return (i + 1);
}

template<size_t SIZE>
void QuickSort(int (&arr)[SIZE], int left, int right) {
    if (left < right) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = Partition(arr, left, right);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, left, pi - 1);
        QuickSort(arr, pi + 1, right);
    }
}

#endif //FINALTEST_QUICKSORT_H
