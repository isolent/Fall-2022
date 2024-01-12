#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <int> g_l[420];
vector <int> g_w[420];
int arr[406][406];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        g_w[a].push_back(b);
        g_w[b].push_back(a);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == 0 and i != j) {
                g_l[i].push_back(j);
            }
        }
    }
    queue <int> qq;
    vector <bool> used(n + 1);
    vector <int> dd(n + 1);

    qq.push(0);
    used[0] = true;

    while (!(qq.empty())) {
        int v = qq.front();
        qq.pop();
        for (int i = 0; i < g_w[v].size(); i++){
            int to = g_w[v][i];
            if (!(used[to])) {
                used[to] = true;
                qq.push(to);
                dd[to] = dd[v] + 1;
            }
        }
    }
    queue <int> q1;
    vector <bool> used1(n + 1);
    vector <int> d1(n + 1);
    q1.push(0);
    used1[0] = true;
    while(!(q1.empty())) {
        int v = q1.front();
        q1.pop();
        for (int i = 0; i < g_l[v].size(); i++){
            int to = g_l[v][i];
            if (!used1[to]) {
                used1[to] = true;
                q1.push(to);
                d1[to] = d1[v] + 1;
            }
        }
    }

    if (!used1[n-1] or !used[n-1]) {
        cout << -1;
    }
    else {
        cout << max(dd[n-1], d1[n-1]);
    }
}