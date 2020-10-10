//
// Created by Ridd on 2020/10/08/008.
//

#include "Test.h"

void Show_Result(int playerNum, std::vector<std::vector<int>> &table) {
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

int main() {
    int playerNum(6);
    int duration = playerNum % 2 == 0 ? (playerNum - 1) : playerNum;
    //建立一个存储日程表的二维数组table，其中一行代表一天，从第一列开始每一列代表一个选手
    //即第i行j列表示第i天第j个选手的对手编号
    std::vector<std::vector<int>> table(playerNum + 2, std::vector<int>(duration + 1));
    for (int i = 1; i <= playerNum; i++) {
        table[i][0] = i;
    }

    Schedule(playerNum, table);
    Show_Result(playerNum, table);
    return 0;
}