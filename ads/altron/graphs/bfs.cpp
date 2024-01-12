#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MXN = 100005;
vector <int> g[MXN];
vector <int> p(MXN);
vector <int> d(MXN);
bool used[MXN];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            int x; cin >> x;
            if (x == 1){
                g[i].push_back(j);
            }
        }
    }

    int s, f;
    cin >> s >> f;
    queue <int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()){
        int v = q.front();
        for (int i = 0; i < g[v].size(); ++i){
            int to = g[v][i];
            if (!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
        q.pop();
    }

    // for(int i = 1; i <= n; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << p[i] << " ";
    // }

    if (used[f]) cout << d[f] << endl;
    else cout << -1 << endl;
}