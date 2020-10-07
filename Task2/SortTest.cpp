//
// Created by 马嘉骥 on 2020/9/29.
//
#undef _HAS_STD_BYTE

#include "Header/SortTest.h"
#include<algorithm>

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
        cout << arr[i] << "\t";
    cout << endl;
}

void SleepCP(int milliseconds) // 跨平台 sleep 函数
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif // _WIN32
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
            MergeSort(sortedArr, size);
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
    int *correctArr = new int[size];
    for (long long i = 0; i < size; i++) {
        correctArr[i] = arr[i];
    }
    sort(correctArr,correctArr+size);
    int flag = 1;
    for (long long i = 0; i < size; i++) {
        if (sortedArr[i] != correctArr[i])
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
            MergeSort(sortedArr, size);
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

    long long size = 7;
    int *arr = new int[size];

    CorrectnessTest(arr, size, 0, -100, 100);
    CorrectnessTest(arr, size, 0, INT_MIN, INT_MIN);
    CorrectnessTest(arr, size, 0, INT_MAX, INT_MAX);
    CorrectnessTest(arr, size, 0, 0, 0);

    //sleep to refresh the random number generator engine's seed
    SleepCP(1000);
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

    delete[] arr;
    size = 1000;
    arr = new int[size];
    cout << "Array size: " << size << endl;
    PerfTest(arr, size, 0, INT_MIN, INT_MAX);
    PerfTest(arr, size, 1, INT_MIN, INT_MAX);
    PerfTest(arr, size, 2, INT_MIN, INT_MAX);

    delete[] arr;
    size = 10000;
    arr = new int[size];
    cout << "Array size: " << size << endl;
    PerfTest(arr, size, 0, INT_MIN, INT_MAX);
    PerfTest(arr, size, 1, INT_MIN, INT_MAX);
    PerfTest(arr, size, 2, INT_MIN, INT_MAX);

    delete[] arr;
    size = 100000;
    arr = new int[size];
    cout << "Array size: " << size << endl;
    PerfTest(arr, size, 0, INT_MIN, INT_MAX);
    PerfTest(arr, size, 1, INT_MIN, INT_MAX);
    PerfTest(arr, size, 2, INT_MIN, INT_MAX);
    /*

    auto start = chrono::system_clock::now();
    sort(arr, arr + size);
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << endl << "STL sort\nTime elapsed: " << duration.count() << " us.\t" << endl;

    //PerfTest(arr, size, 2, INT_MIN, INT_MAX);
    */
}
