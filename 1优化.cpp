#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

const int n = 10000;
int a[n][n], b[n], sum[n];

int main()
{
    long long head, tail, freq;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            a[i][j] = i + j;
    }

    int gap = 100;
    for (int k = 100; k <= n; k += gap) {
        for (int i = 0; i < k; i++) {
            sum[i] = 0;
        }

        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
        
        //优化算法
        for (int j = 0; j < k; j++)
            for (int i = 0; i < k; i++)
                sum[i] += a[j][i] * b[j];

        QueryPerformanceCounter((LARGE_INTEGER*)&tail);

        cout << "n=" << k << " time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
        if (k == 1000)gap = 2000;
        if (k == 7000)gap = 3000;


    }

    return 0;
}