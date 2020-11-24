//
// Created by 马嘉骥 on 2020/9/28.
//

#ifndef FINALTEST_MAXSUBSEQTEST_H
#define FINALTEST_MAXSUBSEQTEST_H

#include<iostream>
#include<Windows.h>
//#include<profileapi.h>
#include<profile.h>
#include<functional>
#include<stdlib.h>
#include<ctime>

using namespace std;

typedef std::function<int(int *, int)> testFunc;


int RandomListGen(int *A, int num, int range);

#endif //FINALTEST_MAXSUBSEQTEST_H
