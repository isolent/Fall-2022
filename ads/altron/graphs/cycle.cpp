#include <iostream>
#include <vector>
using namespace std;

const int MXN = 100005;
vector <int> g[MXN];
// bool used[MXN];

int N = 0;
int D = 1;
int V = 2;

int state[MXN];
void dfs(int v){
    if(state[v] == D) {
        cout << "Cycle detected" << endl;
        exit(0);
    }

    if (state[v] == v) return;
    state[v] = D;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    state[v] = V;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if (state[i] == N) dfs(i);
    }
    cout << "Graph is acyclic";
    // dfs (3);
}