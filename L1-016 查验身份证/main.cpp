#include <iostream>
#include <string>

using namespace std;

bool bumanzu(string s);

int main()
{
    int n, i, flag = 0;
    cin >> n;
    for(i = 0; i < n; i++){
        string s;
        cin >> s;
        if(bumanzu(s)){
            flag++;
        }
    }
    if(flag == 0){
        cout << "All passed";
    }
    return 0;
}

bool bumanzu(string s)      //if bumanzu, return true. and output the string
{
    int i, a[18], sum = 0, z;
    for(i = 0; i < 17; i++){
        if(!isdigit(s[i])){
            cout << s <<endl;
            return true;
        }
        a[i] = s[i] - '0';
    }

    if(s[17] == 'X'){
        a[17] = 10;
    } else{
        a[17] = s[17] - '0';
    }

    int b[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};      //wight

    for(i = 0; i < 17; i++){
        sum += a[i]*b[i];
    }
    z = sum % 11;

    int M[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};

    if(a[17] == M[z]){
        return false;
    }else{
        cout << s <<endl;
        return true;
    }
}
