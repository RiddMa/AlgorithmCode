//
// Created by Ridd on 2020/10/08/008.
//

#include "../Headers/Driver.h"

void ShowResult2Console(int playerNum, std::vector<std::vector<int>> &table) {
    std::cout << "The tournament shall be arranged as follow:" << std::endl;
    int daysTotal = daysTotal = playerNum % 2 == 0 ? playerNum - 1 : playerNum;
    for (int i = 0; i <= daysTotal; i++) {
        for (int j = 0; j <= playerNum; j++) {
            if (i == 0 && j == 0) {
                std::cout.setf(std::ios::left);
                std::cout.width(15);
                std::cout << "Player Number:" << std::cout.fill(' ');
            } else if (j == 0) {
                std::string day("Day:");
                day.append(std::to_string(i));
                std::cout.width(15);
                std::cout << day << std::cout.fill(' ');
            } else {
                std::cout.width(5);
                std::cout << table[j][i] << std::cout.fill(' ');
            }
        }
        std::cout << std::endl;
    }
}


void ShowResult2File(int playerNum, std::vector<std::vector<int>> &table) {
    std::fstream file;
    file.open("../result.txt", std::ios::out | std::ios::trunc);

    int daysTotal = daysTotal = playerNum % 2 == 0 ? playerNum - 1 : playerNum;
    for (int i = 0; i <= daysTotal; i++) {
        for (int j = 1; j <= playerNum; j++) {
            file << table[j][i] << ",";
        }
        file << std::endl;
    }
    file.close();
}


int main() {
    int playerNum(7);
    int duration = playerNum % 2 == 0 ? (playerNum - 1) : playerNum;
    std::vector<std::vector<int>> table(playerNum + 2, std::vector<int>(duration + 1));
    for (int i = 1; i <= playerNum; i++) {
        table[i][0] = i;
    }

    Schedule(playerNum, table);

    ShowResult2Console(playerNum, table);
    ShowResult2File(playerNum, table);

    CorrTest();
    PerfTest();

    return 0;
}