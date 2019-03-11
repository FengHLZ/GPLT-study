#include <iostream>
#include <algorithm>        //fill()
#include <cstdio>           //stdio.h
#include <climits>          //INT_MAX

using namespace std;

int n, m, c1, c2;           //node, edge, start, end
int e[510][510], dis[510], weight[510], num[510], pre[510], w[510];
bool visit[510];

void printPath(int);

int main()
{
    int i, j, v;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    fill(e[0], e[0] + 510 * 510, INT_MAX);
    fill(dis, dis + 510, INT_MAX);

    int a, b, c;
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = c;
        e[b][a] = c;
    }

    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;

    for(i = 0; i < n; i++){
        int u = -1, minn = INT_MAX;
        for(j = 0; j < n; j++){
            if(visit[j] == false && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1){
            break;
        }
        visit[u] = true;
        for(v = 0; v < n; v++){
            if(visit[v] == false && e[u][v] != INT_MAX){
                if(dis[u] + e[u][v] < dis[v]){
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                    pre[v] = u;
                }
                else if(dis[u] + e[u][v] == dis[v]){
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
    printf("%d %d\n", num[c2], w[c2]);
    printPath(c2);
    return 0;
}

void printPath(int v)
{
    if(v == c1){
        printf("%d", v);
        return;
    }else{
        printPath(pre[v]);
        printf(" %d", v);
    }
}
