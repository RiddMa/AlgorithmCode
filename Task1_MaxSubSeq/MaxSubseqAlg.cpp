//
// Created by 马嘉骥 on 2020/9/28.
//

#include "MaxSubseqAlg.h"

int MaxSubsequenceSumN3(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            ThisSum = 0;
            for (int k = i; k <= j; k++) {
                if ((A[k] > 0 && ThisSum + A[k] < ThisSum) || (A[k] < 0 && ThisSum + A[k] > ThisSum))
                    throw "Error: Data out of bound!\n";
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}


int MaxSubsequenceSumN2(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; i++) {
        ThisSum = 0;
        for (int j = i; j < N; j++) {
            if ((A[j] > 0 && ThisSum + A[j] < ThisSum) || (A[j] < 0 && ThisSum + A[j] > ThisSum))
                throw "Error: Data out of bound!\n";
            ThisSum += A[j];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}


int DivideCountSubsequence(int A[], int left, int right) {
    int ThisSum, MaxSum = 0, mid = (left + right) / 2;
    //check termination condition
    if (left < right) {

        int LeftMax = DivideCountSubsequence(A, left, mid);
        int RightMax = DivideCountSubsequence(A, mid + 1, right);
        int Mid2LeftMax = 0, Mid2RightMax = 0;

        for (int i = mid, ThisSum = 0; i >= left; i--) {
            if ((A[i] > 0 && ThisSum + A[i] < ThisSum) || (A[i] < 0 && ThisSum + A[i] > ThisSum))
                throw "Error: Data out of bound!\n";
            ThisSum += A[i];
            if (ThisSum >= Mid2LeftMax)
                Mid2LeftMax = ThisSum;
        }
        for (int i = mid + 1, ThisSum = 0; i <= right; i++) {
            if ((A[i] > 0 && ThisSum + A[i] < ThisSum) || (A[i] < 0 && ThisSum + A[i] > ThisSum))
                throw "Error: Data out of bound!\n";
            ThisSum += A[i];
            if (ThisSum >= Mid2LeftMax)
                Mid2RightMax = ThisSum;
        }
        if (Mid2LeftMax + Mid2RightMax < Mid2LeftMax)throw "Error: Data out of bound!\n";
        int MidMax = Mid2LeftMax + Mid2RightMax;

        if (LeftMax > RightMax) {
            if (LeftMax > MidMax)
                MaxSum = LeftMax;
            else
                MaxSum = MidMax;
        } else {
            if (RightMax > MidMax)
                MaxSum = RightMax;
            else
                MaxSum = MidMax;
        }
    } else if (left == right) return A[left];
    return MaxSum;
}


int MaxSubsequenceSumNlogN(int A[], int N) {
    return DivideCountSubsequence(A, 0, N - 1);
}


int MaxSubsequenceSumN(int A[], int N) {
    int ThisSum = 0, MaxSum = 0;
    for (int i = 0; i < N; i++) {
        if ((A[i] > 0 && ThisSum + A[i] < ThisSum) || (A[i] < 0 && ThisSum + A[i] > ThisSum))
            throw "Error: Data out of bound!\n";
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}