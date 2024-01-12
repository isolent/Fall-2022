#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector <int> g[505];
int used[505];
stack <int> s;
vector <int> path_of_cycle; 

bool dfs(int v, int a, int b){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];

        if(v == a && b == to) continue;
        
        if(!used[to]) {
            if (dfs(to, a, b)) return true;
        } 
        else if (used[to] == 1) return true;
    }
// if used[i] == 0 - new vertice 
// if used[i] == 1 - in process
// if used[i] == 2 - used
     used[v] = 2;
     return false;
}

bool dfs2(int v){
    used[v] = 1;
    s.push(v);

    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if( !used[to] ){
            if (dfs2(to)) return true;
        } else if (used[to] == 1){
            while(s.top() != to){
                path_of_cycle.push_back(s.top());
                s.pop();
            }

            path_of_cycle.push_back(to);
            path_of_cycle.push_back(v);

            reverse(path_of_cycle.begin(), path_of_cycle.end());
            return true;
        }
    } 
    used[v] = 2;
    if (!s.empty()) s.pop();
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ok = dfs2(i);
            if (ok) break;
        }
    }
    
    if (!ok) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < path_of_cycle.size() - 1; i++) {
        int u = path_of_cycle[i];
        int v = path_of_cycle[i + 1];
       
        for (int j = 1; j <= n; j++) {
            used[j] = 0;
        }

        ok = 0;

        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                ok |= dfs(j, u, v);
            }
        }
        if (!ok) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}