#include <iostream>
#include <vector>
using namespace std;

const int MXN = 100005;
vector <int> g[MXN];

int N = 0;
int D = 1;
int V = 2;

string ans;
vector <int> path;
int state[MXN];

void dfs(int v){
    if(state[v] == D) {
        cout << "Impossible";
        exit(0);
    }

    if (state[v] == V) return;
   
    state[v] = D;
   
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }

    state[v] = V;
    path.push_back(v);
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
    cout << "Possible" << endl;
    for (int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
    
}