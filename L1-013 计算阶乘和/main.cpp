#include <iostream>

using namespace std;

int jiecheng(int );

int main()
{
    int N, S = 0, i;
    cin >> N;
    for(i = 0; i < N; i++){
        S += jiecheng(i+1);
    }
    cout << S;
    return 0;
}

int jiecheng(int n)
{
    if(n == 1) return 1;
    else return n*jiecheng(n-1);
}
