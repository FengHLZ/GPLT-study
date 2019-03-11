#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int first = 0, i, maxnum = sqrt(num) + 1, j, temp = 1, len = 0;
    for(i = 2; i <= maxnum; i++){
        for(j = i; j <= maxnum; j++){
            temp *= j;
            if(num % temp != 0) break;
        }
        if(j - i > len){
            len = j - i;
            first = i;
        }
        temp = 1;
    }
    if(first == 0){
        cout << 1 << endl << num;
    } else {
        cout << len << endl;
    }
    for(i = 0; i < len - 1; i++){
        cout << first << '*';
        first++;
    }
    if(first != 0)
        cout << first;

    return 0;
}
