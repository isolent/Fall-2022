#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MXN = 1e5 + 7;
const int INF = 1e9;
vector <pair<int, int > > g[MXN];
bool used[MXN];
int d[MXN];
int n, m;

void dijkstra(int s){
    for (int i = 1; i <= n; i++){
        d[i] = INF;
    }

    d[s] = 0;

    for (int i = 0; i < n; i++){
        int u = -1;
        for (int j = 1; j <= n; j++){
            if ((!used[j] && (u == -1 || d[j] < d[u] ))){
                u = j;
            }
        }

        if (d[u] == INF) break; //nowhere to go

        used[u] = true;
        for (int j = 0; j < g[u].size(); j++){
            pair <int, int> p = g[u][j];
            int v = p.first, w = p.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    dijkstra(1);

    for (int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
}