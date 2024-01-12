#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
const int MXN = 2e5 + 6;
int INF = 1e9;
vector <int> de(MXN, INF);
vector <pair <int, int> > g[MXN];

int dijkstra(int s, int stop){
    de.clear();
    for(int i = 0; i < MXN; i++){
        de[i] = INF;
    }

    de[s] = 0;

    set <pair <int, int > > q;
    q.insert(make_pair(de[s], s));
    while (!(q.empty())){
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int j = 0; j < g[v].size(); j++){
            int to = g[v][j].first;
            int l = g[v][j].second;
            if (de[v] + l < de[to]){
                q.erase(make_pair(de[to], to));
                de[to] = de[v] + l;
                q.insert(make_pair(de[to], to));
            }
        }
    }
    return de[stop];
}  

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    int q,w,e,r; 
    cin >> q >> w >> e >> r; 
    int a,b; 
    a = dijkstra(q,w) + dijkstra(w,e) + dijkstra(e,r); 
    b = dijkstra(q,e) + dijkstra(e,w) + dijkstra(w,r) ; 


    if (min(a, b) <= INF){
        cout << min(a, b);
    } else {
        cout << -1;
    }
    return 0;
}