#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MXN = 2e5 + 5;

int pp[MXN];
int rk[MXN];

int cnt;

void dsu () {
    for (int i = 0; i < 200005; i++) {
        pp[i] = i;
        rk[i] = 1;
    }
}

int root(int v){
    if(pp[v] == v) return v;
    else return pp[v] = root(pp[v]);
}

bool merge(int a, int b){
    int rootof_a = root(a);
    int rootof_b = root(b);
    if (rootof_a == rootof_b) return true;
    else {
        if (rk[rootof_a] < rk[rootof_b]){
            pp[rootof_a] = rootof_b;
        } else if (rk[rootof_b] < rk[rootof_a]){
            pp[rootof_b] = rootof_a; 
        } else {
            pp[rootof_a] = rootof_b;
            rk[rootof_b]++;
        }
        return false;
    }
}

vector<int> g[MXN];
vector<int> res;

int main(){
    int n, m;
    cnt = 0; 
    dsu();
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = n; i > 1; i --){
        cnt++;
        for (int j = 0; j < g[i].size(); j++){
            if (g[i][j] > i and root(i) != root(g[i][j])){
                cnt--;
                merge(i, g[i][j]);
                }
            }
        res.push_back(cnt);
    }

    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    cout << 0 << endl;
}