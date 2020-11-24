//
// Created by 马嘉骥 on 2020/9/28.
//

#include <climits>
#include "MaxSubseqTest.h"
#include "MaxSubseqAlg.h"

int RandomListGen(int *A, int num, int range) {
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        A[i] = (rand() % range - range / 2);
    }
    return num;
}

/*
#define RAND 0
#define ZERO 1
#define MAX 2
#define MIN 3
#define RANDSAME 4
*/
void ListGen(int *List, int arg, int num, int range) {
    switch (arg) {
        case 0: {
            srand(time(NULL));
            for (int i = 0; i < num; i++) {
                List[i] = (rand() % range - range / 2);
            }
            break;
        }
        case 1: {
            for (int i = 0; i < num; i++) {
                List[i] = 0;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < num; i++) {
                List[i] = INT_MAX;
            }
            break;
        }
        case 3: {
            for (int i = 0; i < num; i++) {
                List[i] = INT_MIN;
            }
            break;
        }
        case 4: {
            srand(time(NULL));
            int value = rand() % range - range / 2;
            for (int i = 0; i < num; i++) {
                List[i] = value;
            }
            break;
        }
    }
}

long long CountTime(testFunc func, int *array, int N) {
    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);

    // Activity to be timed
    func(array, N);

    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

    ElapsedMicroseconds.QuadPart *= 1000000;
    ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

    return ElapsedMicroseconds.QuadPart;
}

void perfTest() {
    int size;
    cout << "\nRunning performance test:" << endl;
    cout << "Input sequence size:" << endl;
    cin >> size;
    int *A = new int[size];

    //test rand
    for (int i = 0; i < 5; i++) {
        ListGen(A, i, size, 1000);
        switch (i) {
            case 0:
                cout << "Testing RANDOM sequence\n";
                break;
            case 1:
                cout << "Testing ZERO sequence\n";
                break;
            case 2:
                cout << "Testing INT_MAX sequence\n";
                break;
            case 3:
                cout << "Testing INT_MIN sequence\n";
                break;
            case 4:
                cout << "Testing RANDOMSAME sequence\n";
                break;
        }
        try {
            cout << "Time used for O(N): " << CountTime(MaxSubsequenceSumN, A, size) << " us" << endl;
            cout << "Time used for O(NlogN): " << CountTime(MaxSubsequenceSumNlogN, A, size) << " us" << endl;
            cout << "Time used for O(N2): " << CountTime(MaxSubsequenceSumN2, A, size) << " us" << endl;
            cout << "Time used for O(N3): " << CountTime(MaxSubsequenceSumN3, A, size) << " us" << endl;
        }
        catch (const char *msg) {
            cerr << msg << endl;
        }
    }
}

void correctnessTest() {
    cout << "Running correctness test:" << endl;
    try {
        int A[] = {1, 2, 3, 4, 5};
        cout << MaxSubsequenceSumN(A, 5) << endl;
        cout << MaxSubsequenceSumNlogN(A, 5) << endl;
        cout << MaxSubsequenceSumN2(A, 5) << endl;
        cout << MaxSubsequenceSumN3(A, 5) << endl;
        cout << endl;
    }
    catch (const char *msg) {
        cerr << msg << endl;
    }

    try {
        int B[] = {0, 0, 0, 0, 0};
        cout << MaxSubsequenceSumN(B, 5) << endl;
        cout << MaxSubsequenceSumNlogN(B, 5) << endl;
        cout << MaxSubsequenceSumN2(B, 5) << endl;
        cout << MaxSubsequenceSumN3(B, 5) << endl;
        cout << endl;
    }
    catch (const char *msg) {
        cerr << msg << endl;
    }

    try {
        int C[] = {INT_MAX, INT_MAX};
        cout << MaxSubsequenceSumN(C, 2) << endl;
        cout << MaxSubsequenceSumNlogN(C, 2) << endl;
        cout << MaxSubsequenceSumN2(C, 2) << endl;
        cout << MaxSubsequenceSumN3(C, 2) << endl;
        cout << endl;
    }
    catch (const char *msg) {
        cerr << msg << endl;
    }

    try {
        int D[] = {INT_MIN, INT_MIN};
        cout << MaxSubsequenceSumN(D, 2) << endl;
        cout << MaxSubsequenceSumNlogN(D, 2) << endl;
        cout << MaxSubsequenceSumN2(D, 2) << endl;
        cout << MaxSubsequenceSumN3(D, 2) << endl;
        cout << endl;
    }
    catch (const char *msg) {
        cerr << msg << endl;
    }

    try {
        int E[] = {INT_MIN, INT_MAX};
        cout << MaxSubsequenceSumN(E, 2) << endl;
        cout << MaxSubsequenceSumNlogN(E, 2) << endl;
        cout << MaxSubsequenceSumN2(E, 2) << endl;
        cout << MaxSubsequenceSumN3(E, 2) << endl;
        cout << endl;
    }
    catch (const char *msg) {
        cerr << msg << endl;
    }
}

int main() {
    correctnessTest();
    perfTest();
    return 0;
}