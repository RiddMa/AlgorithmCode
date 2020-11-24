//
// Created by 马嘉骥 on 2020/11/23.
//

#include "Flower.h"

int Method[105][105];
//int Solution[105];
int flowerMax[105];

void flower(int flowerType, int flowerPot) {
    cin >> flowerType >> flowerPot;
    for (int i = 1; i <= flowerType; i++) {
        cin >> flowerMax[i];
    }
    Method[0][0] = 1; // 不摆放花也是一种方案
    // 花的种类
    for (int i = 1; i <= flowerType; i++) {
        // 花的朵数
        for (int j = 0; j <= flowerPot; j++) {
            // k从0开始表示不一定所有种类的花都要摆上
            // 选择min（flowerMax[i], j）是因为第i种花一共只有a[i]盆，要够放
            for (int k = 0; k <= min(flowerMax[i], j); k++) {
                Method[i][j] = (Method[i][j] + Method[i - 1][j - k]) % 1000007;

            }
        }
    }
    cout << Method[flowerType][flowerPot] % 1000007 << endl;
}
