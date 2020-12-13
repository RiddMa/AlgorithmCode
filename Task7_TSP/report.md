# 旅行商问题

班级：2018211303	姓名：马嘉骥	学号：2018211149

## 算法目的

某售货员要到若干城市去推销商品，已知各城市之间的路程，他要选定一条从驻地出发，经过每个城市一遍，最后回到住地的路线，使总的路程最短。

## 剪枝策略

* 如果当前正在考虑的顶点j与当前路径中的末端结点i没有边相连， 即w[i, j]= INF, 则不必搜索j所在分支。

* 如果curnCost(i) ≥ bestCost, 则停止搜索curnPath[i]分支及其下面的层 ， 其中，bestCost代表到目前为止,在前面的搜索中，从其它已经搜索过的路径中，找到的最佳完整回路的权和（总长度）

## 解空间树

```mermaid
stateDiagram-v2
[*] --> 1 : 1
1 --> 2 : 2
2 --> 3 : 3
3 --> 4 : 4
2 --> 5 : 4
5 --> 6[cut] : 3
1 --> 7 : 3
7 --> 8 : 2
8 --> 9 : 4
7 --> 10[cut] : 4
1 --> 11 : 4
11 --> 12 : 3
12 --> 13[cut] : 2
11 --> 14 : 2
14 --> 15 : 3

[*] --> 16 : 2
16 --> 17[cut] : 1
16 --> 18 : 3
18 --> 19 : 1
19 --> 20[cut] : 4
18 --> 21[cut] : 4
16 --> 22 : 4
22 --> 23[cut] : 3
22 --> 24 : 1
24 --> 25[cut] : 3

[*] --> 26 : 3
26 --> 27 : 2
27 --> 28[cut] : 1
27 --> 29 : 4
29 --> 30[cut] : 1
26 --> 31 : 1
31 --> 32[cut] : 2
31 --> 33 : 4
33 --> 34[cut] : 2
26 --> 35 : 4
35 --> 36[cut] : 2
35 --> 37 : 1
37 --> 38[cut] : 2

[*] --> 39 : 4
39 --> 40 : 2
40 --> 41 : 3
41 --> 42[cut] : 1
40 --> 43[cut] : 1

39 --> 44 : 3
44 --> 45[cut] : 2
44 --> 46[cut] : 1

39 --> 47 : 1
47 --> 48 : 3
48 --> 49[cut] : 2
47 --> 50[cut] : 2
```

## 源码

```c++
#include<iostream>

using namespace std;

const int INF = 0x7f7f7f;
int n, curnCost = 0, bestCost = INF;
int graph[4][4] = {
        {INF, 30,  6,   4},
        {30,  INF, 5,   10},
        {6,   5,   INF, 20},
        {4,   10,  20,  INF}};
int *curnPath, *bestPath;

void travel(int tier) {
    //如果达到解空间树叶子节点
    if (tier == n) {
        if (graph[curnPath[tier - 1]][curnPath[tier]] != INF && graph[curnPath[tier]][1] != INF &&
            (curnCost + graph[curnPath[tier - 1]][curnPath[tier]] + graph[curnPath[tier]][1] < bestCost ||
             bestCost == INF)) {
            for (int i = 0; i < n + 1; i++)
                bestPath[i] = curnPath[i];
            bestCost = curnCost + graph[curnPath[tier - 1]][curnPath[tier]] + graph[curnPath[tier]][1];
        }
        return;
    }
	//从当前节点向下搜索
    for (int i = tier; i < n; i++) {
        if (graph[curnPath[tier - 1]][curnPath[i]] != INF &&
            (curnCost + graph[curnPath[tier - 1]][curnPath[i]] < bestCost
             || bestCost == INF)) {
            swap(curnPath[i], curnPath[tier]);
            curnCost += graph[curnPath[tier - 1]][curnPath[tier]];
            travel(tier + 1);
            curnCost -= graph[curnPath[tier - 1]][curnPath[tier]];
            swap(curnPath[i], curnPath[tier]);
        }
    }
}

void output() {
    cout << bestCost << endl;
    cout << bestPath[1];
    for (int i = 2; i < n + 1; i++)
        cout << " " << bestPath[i];
    cout << " " << bestPath[1] << endl;
}

int main() {
    n = 4;
    curnPath = new int[n + 1];
    bestPath = new int[n + 1];

    for (int i = 0; i < n + 1; i++) {
        curnPath[i] = i;
    }

    travel(2);
    output();

    return 0;
}
```

## 运行结果

```
G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug\TSK7.exe
25
1 2 3 4 1

Process finished with exit code 0
```

