#include <iostream>
#include <string>

using namespace std;

int main()
{
    int book[256], i;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for(i = 0; i < b.length(); i++){
        book[b[i]] = 1;     //set flag
    }
    for(i = 0; i < a.length(); i++){
        if(book[a[i]] == 1){
            continue;
        }
        cout << a[i];
    }
    return 0;
}
