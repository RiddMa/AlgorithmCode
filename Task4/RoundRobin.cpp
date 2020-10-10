//
// Created by 马嘉骥 on 2020/10/5.
//
/*
- 题目描述：设有n个运动员要进行网球循环赛。设计 一个满足下列条件的比赛日程表:
– 每个选手必须与其他n-1个选手各赛一次; – 每个选手一天只能赛一次;
– 当n是偶数时，循环赛进行n-1天。
– 当n是奇数时，循环赛进行n天。
 */
/*
 * 思路：分治法
 * 先拆分问题，对于用户指定的n，考虑规模为m = ceil(n/2.0)的问题，并解决这个子问题，有两种情况：
 *
 * 子问题是偶数，继续重复上面的动作
 * 子问题是奇数，补充一个虚拟选手m+1，这样一共有偶数个选手，于是继续重复上面的动作
 *
 * 不断拆分直到只剩下两个人，让他们互相比赛即可
 *
 * 回过头来从子问题构造母问题，采取先横向构造、再纵向构造的方法，有两种情况
 *
 * 子问题是偶数，开开心心地正常构造
 * 子问题是奇数，由于之前我们扩充了一个虚拟选手使得问题变为了偶数个选手，这时候我们需要把这个虚拟选手清除，并且把所有与他比赛的人，
 * 相应的位置编号由m+1变为0，表示这天没有比赛（原本和不存在的人比赛那当然相当于没有比赛了）
 *
 * 重复以上的构造方法，直到问题恢复到n的规模，此时问题解决完毕
 */

#include "RoundRobin.h"

void Merge(int playerNum, std::vector<std::vector<int>> &table) {
    int halfPlayerNum = (int) ceil(playerNum / 2.0);
    int daysTotal = playerNum % 2 == 0 ? playerNum - 1 : playerNum;
    int daysMerged = halfPlayerNum % 2 == 0 ? halfPlayerNum - 1 : halfPlayerNum;
    // construct schedule table for the last half player from the first day to daysMerged st day
    for (int i = 1; i <= halfPlayerNum; i++) {
        for (int j = 1; j <= daysMerged; j++) {
            if (table[i][j] != 0) {
                // if player i has rival on day j, let player (i + hPN) play with (i's rival number + hPN)th player
                table[i + halfPlayerNum][j] = table[i][j] + halfPlayerNum;
            } else {
                // if player i has no rival on day j, let i and (i + hPN) be rivals
                table[i + halfPlayerNum][j] = i;
                table[i][j] = i + halfPlayerNum;
            }
        }
    }

    int oddFlag = 0;
    if (table[1][daysMerged] == halfPlayerNum + 1) {
        oddFlag = 1;
    }
    for (int i = 1; i <= halfPlayerNum; i++) {
        for (int j = daysMerged + 1, count = 0; j <= daysTotal; j++, count++) {
            //construct opponent for player i on day j
            int rValue = (count + (i - 1) + oddFlag) % halfPlayerNum + halfPlayerNum + 1;
            table[i][j] = rValue;
            table[rValue][j] = i;
        }
    }
    //remove virtual player if exists
    if (playerNum % 2 == 1) {
        for (int i = 1; i <= 2 * halfPlayerNum; i++) {
            for (int j = 1; j <= daysTotal; j++) {
                if (table[i][j] == playerNum + 1) {
                    table[i][j] = 0;
                }
            }
        }
    }
}

void Schedule(int playerNum, std::vector<std::vector<int>> &table) {
    if (playerNum == 2) {
        table[1][1] = 2;
        table[2][1] = 1;
    } else {
        //if playerNum>2, solve problem n = ceil(playerNum/2.0), if n still>2, continue splitting until n == 2
        Schedule((int) ceil(playerNum / 2.0), table);
        Merge(playerNum, table);
    }
}