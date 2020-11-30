//
// Created by 马嘉骥 on 2020/11/23.
//

#include "Flower.h"

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100 + 5;
const int INF = 0x3f3f3f3f;
int a[maxn][maxn];
int dp[maxn][maxn];
int n, m;

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j], dp[i][j] = -INF;
        }
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        dp[1][1] = a[1][1];

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= m; j++) {
                for (int k = 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
                }
            }
        }
        int ans = -INF;
        for (int i = 1; i <= m; i++) {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}