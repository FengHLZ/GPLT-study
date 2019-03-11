#include <iostream>

using namespace std;

int main()
{
    int n,a;
    char c;
    cin>>n>>c;
    a=(n%2==0)?(n/2):(n/2+1);
    for(int i=a;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}
