#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool used [5007];
vector <int> g[5007];
int dis[5007];
int n;
int col[5007];

void bfs(int s){
    for(int i = 1; i <= n; i++){
        used[i] = 0;
    }

    queue <int> q;
    q.push(s);
    used[s] = 1;
    dis[s] = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = 0; i < g[f].size(); i++){
            int to = g[f][i];
            if (dis[to] > dis[f] + 1){
                dis[to] = dis[f] + 1;
                used[to] = 1;
                q.push(to); 
            }
        }
    }
}

int main(){
    int m, q; cin >> n >> m >> q;
    
    for (int i = 1; i <= m; i++){
        int u, v; 
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++){
        dis[i] = 1e9;
    }

    for (int j = 1; j <= q; j++){
        int v, t;
        cin >> t >> v;
        if (t == 1){
            if (col[v] != 1){
                bfs(v);
                col[v] = 1;
            }
        } else {
            if (dis[v] == 1e9) 
                cout << -1 << endl;
            else 
                cout << dis[v] << endl;
        }
    }
}