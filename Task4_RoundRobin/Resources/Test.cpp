//
// Created by Ridd on 2020/10/20/020.
//

#include "../Headers/Test.h"

void PerfTest() {
    for (int i = 100; i <= 10000; i *= 10) {
        int playerNum = i;
        int daysTotal = playerNum % 2 == 0 ? (playerNum - 1) : playerNum;
        std::vector<std::vector<int>> table(playerNum + 2, std::vector<int>(daysTotal + 1));
        for (int j = 1; j <= playerNum; j++) {
            table[j][0] = j;
        }
        auto start = std::chrono::system_clock::now();
        Schedule(playerNum, table);
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time elapsed for scheduling " << i << " players: " << duration.count() << " us." << std::endl;
    }
}


void CorrTest() {
    for (int i = 15; i <= 18; i++) {
        int playerNum = i;
        int daysTotal = playerNum % 2 == 0 ? (playerNum - 1) : playerNum;
        std::vector<std::vector<int>> table(playerNum + 2, std::vector<int>(daysTotal + 1));
        for (int j = 1; j <= playerNum; j++) {
            table[j][0] = j;
        }
        Schedule(playerNum, table);

        std::vector<int> check(playerNum + 1);
        bool correct = true;
        for (int j = 1; (j <= playerNum) && correct; j++) {
            for (int k = 0; (k <= daysTotal) && correct; k++) {
                if (check[table[j][k]] == 0) {
                    check[table[j][k]] = 1;
                } else {
                    correct = false;
                }
            }
            std::fill(check.begin(), check.end(), 0);
        }

        for (int j = 0; (j <= daysTotal) && correct; j++) {
            for (int k = 1; (k <= playerNum) && correct; k++) {
                if (check[table[k][j]] == 0) {
                    check[table[k][j]] = 1;
                } else {
                    correct = false;
                }
            }
            std::fill(check.begin(), check.end(), 0);
        }

        std::cout << "Result for " << playerNum << " players: ";
        if (correct) {
            std::cout << "Correct." << std::endl;
        } else {
            std::cout << "Wrong." << std::endl;
        }
        std::vector<std::vector<int>>().swap(table);
    }
}
