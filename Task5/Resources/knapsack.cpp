//
// Created by Ridd on 2020/11/15/015.
//

#include "../Headers/knapsack.h"

void Knapsack(int ProdCount, int Capacity, std::vector<int> &ArrWeight, std::vector<int> &ArrValue,
              std::vector<std::vector<int>> &Res) {
    for (int i = 1; i <= ProdCount; ++i) {
        for (int j = 1; j <= Capacity; ++j) {
            if (ArrWeight[i] > j) {// when backpack j can't hold product i
                Res[i][j] = Res[i - 1][j];// give up product i
            } else {
                int value1 = Res[i - 1][j - ArrWeight[i]] + ArrValue[i];// if take product i-1
                int value2 = Res[i - 1][j];// if don't take product i-1
                Res[i][j] = value1 > value2 ? value1 : value2;// which one is better?
            }
        }
    }
}

void KnapsackSmall(int ProdCount, int Capacity, std::vector<int> &ArrWeight, std::vector<int> &ArrValue,
                   std::vector<std::vector<int>> &Res) {

}