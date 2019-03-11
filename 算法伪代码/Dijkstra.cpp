Dijkstra() {
  初始化;
  for(循环n次) {
    u = 使dis[u]最小的还未被访问的顶点的编号;
    记u为确定值;
    for(从u出发能到达的所有顶点v){
      for(v未被访问 && 以u为中介点使s到顶点v的最短距离更优)
        优化dis[v];
    }
  }
}


//邻接矩阵
int n, e[maxv][maxv];
int dis[maxv], pre[maxv];   // pre用来标注当前结点的前一个结点
bool vis[maxv] = {false};   // 都标记为未访问
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);
  dis[s] = 0;               // 起点的距离为0
  for(int i = 0; i < n; i++) pre[i] = i; // 初始状态设每个点的前驱为自身
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {      // 使dis[u]最小的还未被访问的顶点的编号
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return;     // 点找完了， return
    visit[u] = true;
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && e[u][v] != inf && dis[u] + e[u][v] < dis[v]) {    // 从u出发能到达的所有顶点v  v未被访问 && 以u为中介点使s到顶点v的最短距离更优
        dis[v] = dis[u] + e[u][v];
        pre[v] = u; // pre用来标注当前结点的前一个结点
      }
    }
  }
}


//邻接表
struct node {
  int v, dis;
}
vector<node> e[maxv];
int n;
int dis[maxv], pre[maxv];// pre用来标注当前结点的前一个结点
bool vis[maxv] = {false};
for(int i = 0; i < n; i++) pre[i] = i; //初始状态设每个点的前驱为自身
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);
  dis[s] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return ;
    visit[u] = true;
    for(int j = 0; j < e[u].size(); j++) {
      int v = e[u][j].v;
      if(visit[v] == false && dis[u] + e[u][j].dis < dis[v]) {
        dis[v] = dis[u] + e[u][j].dis;
        pre[v] = u;
      }
    }
  }
}


void dfs(int s, int v) {
  if(v == s) {
    printf("%d\n", s);
    return ;
  }
  dfs(s, pre[v]);
  printf("%d\n", v);
}
