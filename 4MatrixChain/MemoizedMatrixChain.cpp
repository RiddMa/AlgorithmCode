//
// Created by 马嘉骥 on 2020/10/12.
//

#include "MemoizedMatrixChain.h"


int MemoizedMatrixChain(int n, int **m, int **s) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) m[i][j] = 0;
        return LookupChain(1, n);
    }
}

int LookupChain(int i, int j) {
    if (m[i][j] > 0)
        return m[i][j];
    if (i == j) return 0;
    int u = LookupChain(i, i) + LookupChain(i + 1, j) + p[i−1]*p[i] * p[j];
    s[i][j] = i;
    for (int k = i + 1; k < j; k++) {
        int t = LookupChain(i, k) + LookupChain(k + 1, j) + p[i−1]*p[k] * p[j];
        if (t < u) {
            u = t;
            s[i][j] = k;
        }
    }
    m[i][j] = u;
    return u;
}

