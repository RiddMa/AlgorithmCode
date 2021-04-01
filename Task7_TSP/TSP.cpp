//
// Created by Ridd on 2020/12/13/013.
//
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