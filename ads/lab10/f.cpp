#include <iostream>
#include <vector>
using namespace std;

const int MXN = 100005;
vector <int> g[MXN];
bool used[MXN];

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (!used[to]) dfs(to);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s, f;
    cin >> s >> f;
    dfs(s);
    if(used[s] and used[f]){
        cout << "YES" << endl;
    } else cout << "NO";
}