#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

const int n=1048576;
int a[n],sum;

void recur(int*a,int n){
    if(n==1)return;
    else{
        for(int i=0;i<n/2;i++)
            a[i]+=a[n-i-1];//后面的加到前面去
        n=n/2;
        recur(a,n);
    }
}

int main()
{
    long long head,tail,freq;//计时器



    for(int k=64;k<=n;k*=2){

        for (int i = 0; i < k; i++)//初始化
        {
            a[i]=1;
        }
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);

        //递归实现两两相加
        recur(a,k);
        sum=a[0];

        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        cout<<"k="<<k<<"      "<<(tail-head)*1000.0/freq<<"ms"<<endl;
    }
    return 0;
}