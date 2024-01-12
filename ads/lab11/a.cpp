#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<pair<int, pair<int, int> > > g;
vector<int> pp;
long long mn_cost = 0;
int n, m;

int dsu_root(int v) {
    if (v == pp[v]) return v;
    else return pp[v] = dsu_root(pp[v]);
}

void combi_dsu(int x, int y){
    x = dsu_root(x);
    y = dsu_root(y);
    pp[x] = y;
}

int main(){
    cin >> n >> m;
    pp.resize(n);
    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;
        g.push_back(make_pair(c, make_pair(l, r)));
    }

    sort(g.begin(), g.end());

    for (int i = 0; i < n; i++){
        pp[i] = i;
    }

    for (int i = 0; i < g.size(); i++){
        int a = g[i].second.first;
        int b = g[i].second.second;
        int cst = g[i].first;

        for (int j = a + 1; j <= b; j++){
            if (dsu_root(a) != dsu_root(j)){
                combi_dsu(a , j);
                mn_cost = mn_cost + cst;
            } else {
                j = pp[a];
            }
        }
    }
    cout << mn_cost << endl;
    return 0;
}