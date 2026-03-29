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
            a[i]+=a[n-i-1];
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

        //多路链式
            int sum1=0,sum2=0;
            for(int i=0;i<k;i+=2){
                sum1+=a[i];
                sum2+=a[i+1];
            }
            sum=sum1+sum2;

        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        cout<<"k="<<k<<"      "<<(tail-head)*1000.0/freq<<"ms"<<endl;
    }
    return 0;
}