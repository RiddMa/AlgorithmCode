//
// Created by 马嘉骥 on 2020/10/5.
//
/*
- 设有n个运动员要进行网球循环赛。设计 一个满足下列条件的比赛日程表:
– 每个选手必须与其他n-1个选手各赛一次; – 每个选手一天只能赛一次;
– 当n是偶数时，循环赛进行n-1天。
– 当n是奇数时，循环赛进行n天。
 */

#include "RoundRobin.h"

int main()
{
    int playerNum(5);
    int duration = playerNum%2==0?(playerNum-1):playerNum;

    

}