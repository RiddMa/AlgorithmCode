//
// Created by 马嘉骥 on 2020/9/29.
//

#include "SortTest.h"

template<size_t SIZE>
void CorrectnessTest(int (&arr)[SIZE], int method, int lower, int upper) {
    RandListGen(arr, lower, upper);
    int sortedArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedArr[i] = arr[i];
    }
    cout << "Generated source array:" << endl;
    PrintArray(arr);
    switch (method) {
        case 0: {
            InsertionSort(sortedArr);
            cout << "Insertion sorted array:" << endl;
            break;
        }
        case 1: {
            MergeSort(sortedArr, 0, SIZE - 1);
            cout << "Merge sorted array:" << endl;
            break;
        }
        case 2: {
            QuickSort(sortedArr, 0, SIZE - 1);
            cout << "Quick sorted array:" << endl;
            break;
        }
    }
    PrintArray(sortedArr);

    //check if sort is correct
    int flag = 1;
    for (int i = 0; i < SIZE - 1; i++) {
        if (sortedArr[i] > sortedArr[i + 1])
            flag = 0;
    }
    if (flag == 1)
        cout << "Sort OK." << endl << endl;
    else
        cout << "Sort failed." << endl << endl;
}


//std::function<void(int[SIZE],int ,int)>func;
typedef std::function<void(int[])> testFunc;

template<size_t SIZE>
void PerfTest(int (&arr)[SIZE], int method, int lower, int upper) {
    //RandListGen(arr, lower, upper);
    int sortedArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedArr[i] = arr[i];
    }
    auto start = chrono::system_clock::now();
    switch (method) {
        case 0:
            InsertionSort(sortedArr);
            break;
        case 1:
            MergeSort(sortedArr, 0, SIZE - 1);
            break;
        case 2:
            QuickSort(sortedArr, 0, SIZE - 1);
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

    cout << "Time elapsed:" << duration.count() << "us." << endl;
}

int main() {
    /*
    CorrectnessTest(arr, 0, -100, 100);
    CorrectnessTest(arr, 0, INT_MIN, INT_MIN);
    CorrectnessTest(arr, 0, INT_MAX, INT_MAX);
    CorrectnessTest(arr, 0, 0, 0);

    //sleep to refresh the random number generator engine's seed
    this_thread::sleep_for(chrono::milliseconds(1000));
    CorrectnessTest(arr, 1, -100, 100);
    CorrectnessTest(arr, 1, INT_MIN, INT_MIN);
    CorrectnessTest(arr, 1, INT_MAX, INT_MAX);
    CorrectnessTest(arr, 1, 0, 0);

    //sleep to refresh the random number generator engine's seed
    this_thread::sleep_for(chrono::milliseconds(1000));
    CorrectnessTest(arr, 2, -100, 100);
    CorrectnessTest(arr, 2, INT_MIN, INT_MIN);
    CorrectnessTest(arr, 2, INT_MAX, INT_MAX);
    CorrectnessTest(arr, 2, 0, 0);
    */
    int arr[10000];
    PerfTest(arr, 0, 0, 100);
    PerfTest(arr, 1, 0, 100);
    PerfTest(arr, 2, 0, 100);
}
