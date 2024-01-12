#include <iostream>
#include <vector>
using namespace std;

vector <int> g[100005];
int used[100005];
int cnt = 0;
void dfs(int v) {

    // if (used[v] == 1) return;
    
    used[v] = 1;

    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (g[to].size() > g[v].size()){
            cnt++;
        }
        dfs(to);
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        u -= 1; v -= 1; 
        g[u].push_back(v);
        // g[v].push_back(u);
    }

    for(int i = 0; i < n ; i++) {
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt ;
}