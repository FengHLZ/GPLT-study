#include <iostream>

using namespace std;

int main()
{
    int N, M, i, j;
    cin >> N;
    struct zuowei{
        string zhunkao;
        int shiji;
        int kaoshi;
    }a[N];

    for(i = 0; i<N; i++){
        cin >> a[i].zhunkao >> a[i].shiji >> a[i].kaoshi;
    }

    cin >> M;
    int b[M];

    for(i = 0; i < M; i++){
        cin >> b[i];
    }

    for(j = 0; j < M; j++){
        for(i = 0; i < N; i++){
            if(b[j]==a[i].shiji){
                cout << a[i].zhunkao << " " << a[i].kaoshi << endl;
            }
        }
    }
    return 0;
}
