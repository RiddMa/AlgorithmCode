//
// Created by 马嘉骥 on 2020/9/28.
//

#include "MergeSort.h"


// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void Merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Merge the temp arrays back into arr[left..right]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* left is for left index and right is right index of the
   sub-array of arr to be sorted */
void MergeSort(int *arr, int SIZE, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for
        // large left and h
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(arr, SIZE, left, mid);
        MergeSort(arr, SIZE, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}