//
// Created by 马嘉骥 on 2020/9/29.
//

#include "SortTest.h"

int main() {
    int arr[10];
    RandListGen(arr, 0, 100);
    printArray(arr);
    InsertionSort(arr);
    printArray(arr);
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    RandListGen(arr, 0, 100);
    printArray(arr);
    MergeSort(arr, 0, 9);
    //RandListGen(arr, 0, 100);
    printArray(arr);

}
