//
// Created by Ridd on 2020/11/15/015.
//

#include "../Headers/main.h"

#include "../Headers/knapsack.h"

int main() {
    int ProdCount, Capacity;
    std::vector<int> ArrWeight(1, 0);
    std::vector<int> ArrValue(1, 0);

    std::cin >> ProdCount >> Capacity;
    for (int i = 1; i <= ProdCount; ++i) {
        int tmp;
        std::cin >> tmp;
        ArrWeight.push_back(tmp);
    }
    for (int i = 1; i <= ProdCount; ++i) {
        int tmp;
        std::cin >> tmp;
        ArrValue.push_back(tmp);
    }

    std::vector<std::vector<int>> Res(ProdCount + 1, std::vector<int>(Capacity + 1, 0));

    Knapsack(ProdCount, Capacity, ArrWeight, ArrValue, Res);

    std::cout << Res[ProdCount][Capacity] << std::endl;

    std::vector<int> Res1(Capacity + 1, 0);

    KnapsackN(ProdCount, Capacity, ArrWeight, ArrValue, Res1);

    std::cout << Res[ProdCount][Capacity] << std::endl;

    return 0;
}