//
// Created by 马嘉骥 on 2020/9/28.
//

#include "MergeSort.h"


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
    {
        for (int q = i; q <= mid; q++)
            B[k++] = A[q];
    }
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
    {
        for (int j = i; j <= n - 1; j++)
            B[j] = A[j];
    }
}

void MergeSort(int A[], int n)
{
    int *B = new int[n];
    for (int step = 1; step < n;)
    {
        MergePass(A, B, step, n);
        step += step;
        //MergePass(B, A, step, n);
        //step += step;
    }
}

int main()
{
    int A[] = {7, 4, 2, 9, 1, 0};
    MergeSort(A, 6);
    for (int i = 0; i < 6; i++)
    {
        std::cout << A[i] << std::endl;
    }
    return 0;
}