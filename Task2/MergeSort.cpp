//
// Created by 马嘉骥 on 2020/9/28.
//

#include "MergeSort.h"

/*
void Merge(int A[], int B[], int left, int mid, int right)
{
    int i(1);
    int j(mid + 1);
    int k(1);
    while ((i <= mid) && (j <= right))
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    if (i > mid)
    {
        for (int q = j; q <= right; q++)
            B[k++] = A[q];
    }
    else
        for (int q = i; q <= mid; q++)
            B[k++] = A[q];
}

void MergePass(int A[], int B[], int step, int n)
{
    int i(0);
    for (; i <= n - 2 * step; i = i + 2 * step)
    {
        Merge(A, B, i, i + step - 1, i + 2 * step - 1);
    }
    if (i + step < n)
        Merge(A, B, i, i + step - 1, n - 1);
    else
        for (int j = i; j <= n - 1; j++)
            B[j] = A[j];
}

void MergeSort(int A[], int n)
{
    int *B = new int[n];
    for (int step = 1; step < n;)
    {
        MergePass(A, B, step, n);
        step += step;
        MergePass(B, A, step, n);
        step += step;
    }
}
*/
// Merges two subarrays of arr[]. 
// First subarray is arr[left..mid] 
// Second subarray is arr[mid+1..right] 
void Merge(int arr[], int left, int mid, int right)
{
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
        }
        else {
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
void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for 
        // large left and h 
        int mid = left + (right - left) / 2;

        // Sort first and second halves 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}