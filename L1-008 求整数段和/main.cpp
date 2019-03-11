#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int a, b, sum = 0, j = 0;
    cin>>a>>b;
    for(sum=0;a<=b;a++){
        printf("%5d",a);
        sum+=a;
        j++;
        if(j%5 == 0) cout<<'\n';
    }
    if(j%5 != 0)
        cout << '\n';
    cout << "Sum = " << sum << endl;

    return 0;
}
