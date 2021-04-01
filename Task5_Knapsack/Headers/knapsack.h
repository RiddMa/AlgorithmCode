//
// Created by Ridd on 2020/11/15/015.
//

#ifndef FINALTEST_KNAPSACK_H
#define FINALTEST_KNAPSACK_H

#include <vector>
#include <iostream>

void Knapsack(int ProdCount, int Capacity, std::vector<int> &ArrWeight, std::vector<int> &ArrValue,
              std::vector<std::vector<int>> &Res);

void KnapsackN(int ProdCount, int Capacity, std::vector<int> &ArrWeight, std::vector<int> &ArrValue,
               std::vector<int> &Res);

#endif //FINALTEST_KNAPSACK_H
