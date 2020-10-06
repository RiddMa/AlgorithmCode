//
// Created by 马嘉骥 on 2020/9/29.
//

#include "SortTest.h"
#include <chrono>
#include<thread>

void RandListGen(int *arr, const long long size, int lower, int upper) {
    default_random_engine randE;
    uniform_int_distribution<int> u(lower, upper);
    randE.seed(time(nullptr));
    for (long long i = 0; i < size; i++) {
        arr[i] = u(randE);
    }
}

void PrintArray(int *arr, long long size) {
    for (long long i = 0; i < size; i++)
        cout << arr[i] << "\t\t";
    cout << endl;
}

void CorrectnessTest(int *arr, const long long size, int method, int lower, int upper) {
    RandListGen(arr, size, lower, upper);
    int *sortedArr = new int[size];
    for (long long i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }
    cout << "Generated source array:" << endl;
    PrintArray(arr, size);
    switch (method) {
        case 0: {
            InsertionSort(sortedArr, size);
            cout << "Insertion sorted array:" << endl;
            break;
        }
        case 1: {
            MergeSort(sortedArr, size, 0, size - 1);
            cout << "Merge sorted array:" << endl;
            break;
        }
        case 2: {
            QuickSort(sortedArr, size, 0, size - 1);
            cout << "Quick sorted array:" << endl;
            break;
        }
    }
    PrintArray(sortedArr, size);

    //check if sort is correct
    int flag = 1;
    for (long long i = 0; i < size - 1; i++) {
        if (sortedArr[i] > sortedArr[i + 1])
            flag = 0;
    }
    if (flag == 1)
        cout << "Sort OK." << endl << endl;
    else
        cout << "Sort failed." << endl << endl;
}

void PerfTest(int *arr, long long size, int method, int lower, int upper) {
    RandListGen(arr, size, lower, upper);
    extern PerfCounter pc;
    int *sortedArr = new int[size];
    for (long long i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }
    pc.CountClear();

    auto start = chrono::system_clock::now();
    switch (method) {
        case 0:
            InsertionSort(sortedArr, size);
            break;
        case 1:
            MergeSort(sortedArr, size, 0, size - 1);
            break;
        case 2:
            QuickSort(sortedArr, size, 0, size - 1);
            break;
    }
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    switch (method) {
        case 0:
            cout << "Insertion sort finished" << endl;
            break;
        case 1:
            cout << "Merge sort finished" << endl;
            break;
        case 2:
            cout << "Quick sort finished" << endl;
            break;
    }

    cout << "Time elapsed: " << duration.count() << " us.\t" << endl;
    cout << "Compare times: " << pc.GetCount() << "\tMove times: " << pc.GetMove() << endl;
}

PerfCounter pc;

int main() {
    long long size = 10;
    int *arr = new int[size];
    CorrectnessTest(arr, size, 0, -100, 100);
    CorrectnessTest(arr, size, 0, INT_MIN, INT_MIN);
    CorrectnessTest(arr, size, 0, INT_MAX, INT_MAX);
    CorrectnessTest(arr, size, 0, 0, 0);

    //sleep to refresh the random number generator engine's seed
    std::this_thread::sleep_for(chrono::milliseconds(1000));
    CorrectnessTest(arr, size, 1, -100, 100);
    CorrectnessTest(arr, size, 1, INT_MIN, INT_MIN);
    CorrectnessTest(arr, size, 1, INT_MAX, INT_MAX);
    CorrectnessTest(arr, size, 1, 0, 0);

    //sleep to refresh the random number generator engine's seed
    this_thread::sleep_for(chrono::milliseconds(1000));
    CorrectnessTest(arr, size, 2, -100, 100);
    CorrectnessTest(arr, size, 2, INT_MIN, INT_MIN);
    CorrectnessTest(arr, size, 2, INT_MAX, INT_MAX);
    CorrectnessTest(arr, size, 2, 0, 0);


    pc.CountClear();
    PerfTest(arr, size, 0, INT_MIN, INT_MAX);

    //RandListGen(arr, size, INT_MIN, INT_MAX);
    //MergeSort(arr, size, 0, size - 1);
    //cout << "OK" << endl;
    PerfTest(arr, size, 1, -10000, 10000);
    //PerfTest(arr, size, 2, INT_MIN, INT_MAX);
}
