Dijkstra() {
  ��ʼ��;
  for(ѭ��n��) {
    u = ʹdis[u]��С�Ļ�δ�����ʵĶ���ı��;
    ��uΪȷ��ֵ;
    for(��u�����ܵ�������ж���v){
      for(vδ������ && ��uΪ�н��ʹs������v����̾������)
        �Ż�dis[v];
    }
  }
}


//�ڽӾ���
int n, e[maxv][maxv];
int dis[maxv], pre[maxv];   // pre������ע��ǰ����ǰһ�����
bool vis[maxv] = {false};   // �����Ϊδ����
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);
  dis[s] = 0;               // ���ľ���Ϊ0
  for(int i = 0; i < n; i++) pre[i] = i; // ��ʼ״̬��ÿ�����ǰ��Ϊ����
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {      // ʹdis[u]��С�Ļ�δ�����ʵĶ���ı��
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return;     // �������ˣ� return
    visit[u] = true;
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && e[u][v] != inf && dis[u] + e[u][v] < dis[v]) {    // ��u�����ܵ�������ж���v  vδ������ && ��uΪ�н��ʹs������v����̾������
        dis[v] = dis[u] + e[u][v];
        pre[v] = u; // pre������ע��ǰ����ǰһ�����
      }
    }
  }
}


//�ڽӱ�
struct node {
  int v, dis;
}
vector<node> e[maxv];
int n;
int dis[maxv], pre[maxv];// pre������ע��ǰ����ǰһ�����
bool vis[maxv] = {false};
for(int i = 0; i < n; i++) pre[i] = i; //��ʼ״̬��ÿ�����ǰ��Ϊ����
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
