#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int MXN = 1e5 + 5;
const int INF = 1e9;
int d[MXN];

struct Edge {
    int a, b, w;
    Edge() {

    }

    Edge (int _a, int _b, int _w){
        a = _a;
        b = _b;
        w = _w;
    }
};

Edge e[MXN];

bool FordBellman(int s){
    for (int i = 0; i <= n; i++){
        d[i] = INF;
    }

    d[s] = 0;

    for(int i = 0; i < n + 1; i++){
        bool any = false;
        for (int j = 0; j < m; j++){
            if (d[e[j].b]  > d[e[j].b + e[j].w] ){
                d[e[j].b]  = d[e[j].b + e[j].w];
                any = true;
            }
        }
        if (!any ) return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[2 * i ] = Edge(u, v, w);
        e[2 * i + 1] = Edge(u, v, w);
    }

    FordBellman(1);

    for(int i = 1; i <= n; i++){
        cout << d[i] << endl;
    }
}