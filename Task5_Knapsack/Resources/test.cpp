//
// Created by Ridd on 2020/11/16/016.
//

#include "../Headers/test.h"
#include "../Headers/knapsack.h"

void GenRandArr(int size, std::vector<int> &arr) {
    std::random_device rd;
    std::default_random_engine randE{rd()};
    std::uniform_int_distribution<int> u(0, 20);

    for (int i = 1; i <= size; ++i) {
        arr.push_back(u(randE));
    }
}

void PerfTest(int prodCount, int capacity, int funType) {
    std::vector<int> ArrWeight(1, 0), ArrValue(1, 0);

    GenRandArr(prodCount, ArrWeight);
    GenRandArr(prodCount, ArrValue);

    auto start = std::chrono::system_clock::now();

    if (funType == 0) {
        std::vector<std::vector<int>> Res(prodCount + 1, std::vector<int>(capacity + 1, 0));
        Knapsack(prodCount, capacity, ArrWeight, ArrValue, Res);
    } else if (funType == 1) {
        std::vector<int> Res(capacity + 1, 0);
        KnapsackN(prodCount, capacity, ArrWeight, ArrValue, Res);
    }

    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time used for ";
    if (funType == 0) {
        std::cout << "Knapsack algorithm with space O(n*C):\t";
    } else if (funType == 1) {
        std::cout << "Knapsack algorithm with space O(C):\t";
    }
    std::cout << duration.count() << "us." << std::endl;

}