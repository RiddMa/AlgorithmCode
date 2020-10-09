//
// Created by Ridd on 2020/10/08/008.
//

#include "Test.h"

void Show_Result(int playerNum, int **table)//将结果按行（即按天）输出到文件中
{

    std::cout << "The tournament shall be arranged as follow:" << std::endl;
    int daysTotal = daysTotal = playerNum % 2 == 0 ? playerNum : playerNum - 1;
    std::cout << "选手编号: ";
    for (int i = 0; i <= daysTotal; i++) {
        if (i)
            std::cout << i;
        for (int j = 1; j <= playerNum; j++) {
            if (!i)
                table[0][j] = j;
            std::cout << table[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int playerNum;
    std::cout << "Please input the number of contestants:" << std::endl;
    std::cin >> playerNum;
    int duration = playerNum % 2 == 0 ? (playerNum - 1) : playerNum;
    //建立一个存储日程表的二维数组table，其中一行代表一天，从第一列开始每一列代表一个选手
    //即第i行j列表示第i天第j个选手的对手编号
    std::vector<std::vector<int>> table(playerNum, std::vector<int>(duration + 1));
    for (int i = 0; i < playerNum; i++) {
        table[i][0] = i + 1;
    }

    Schedule(playerNum, table);
    //Show_Result(playerNum, table);//生成的循环赛表格输出到文件中
    return 0;
}