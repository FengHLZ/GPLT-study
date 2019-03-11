#include<iostream>
using namespace std;
int main(void)
{
    int n,a=2,i,k,l,j,m;
    char c;
    cin>>n>>c;
    m=n;
    n=n-1;

    for(;n>=(4*a-2);a++){
        n=n-(4*a-2);
    }
    a=a-1;
    l=a;

    for(i=1;i<=a-1;i++){
        for(j=1;j<=(2*l-1);j++){
            cout<<c;
        }
        cout<<endl;
        for(k=1;k<=i;k++){
            cout<<" ";
        }
        l--;
    }
    cout<<c<<endl;   //中间一行

    l++;
    for(i=a-1;i>=1;i--){
        for(k=i-1;k>=1;k--){
            cout<<" ";
    }
        for(j=(2*l-1);j>=1;j--){
            cout<<c;
        }
        cout<<endl;
        l++;
    }
    cout<<m-2*a*a+1<<endl;
    return 0;
}
