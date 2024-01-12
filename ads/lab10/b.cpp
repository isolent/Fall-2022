#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> g[100005];
vector <int> d(100005);
bool used[100005];

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

    while (!q.empty()){
        int v = q.front();
        for (int i = 0; i < g[v].size(); ++i){
            int to = g[v][i];
            if (!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
        q.pop();
    }
    if (used[f]) cout << d[f] << endl;
    else cout << -1 << endl;
}