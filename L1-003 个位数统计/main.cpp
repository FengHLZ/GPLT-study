#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char n;
    int a[10]={0},i;
    for(;;){
        n=getchar();
        if(n=='\n') break;
        else a[n-'0']++;
    }

    for(i=0;i<=9;i++){
        if(a[i]!=0)
            cout<<i<<":"<<a[i]<<endl;
    }
    return 0;
}
