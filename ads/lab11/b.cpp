// prim's algorithm
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n; 

// priority queue - бинарная куча
bool used[100005];
vector <pair <int, int> > g[100005];

int main(){
    cin >> n;
    int a[506];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // g[x].push_back(make_pair(y, z));
        // g[y].push_back(make_pair(x, z));
    }

    sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; i++){
        g[1].push_back(make_pair(i, a[1] + a[i]));
        g[i].push_back(make_pair(1, a[1] + a[i]));
    }
    
    int w = 0; 
    priority_queue < pair<int, int>, vector <pair <int, int > >, greater <pair <int, int> > > q;
    q.push (make_pair(0, 1));

    while (!q.empty()){
        pair <int, int> a = q.top();
        q.pop();

        int mst = a.first, v = a.second;

        if(used[v]) continue;

        used[v] = 1;
        w = w + mst;
        int limit = g[v].size();
        for (int i = 0; i < limit; i++) {
            int u = g[v][i].first, len = g[v][i].second;
            if (!used[u]) q.push(make_pair(len, u));
        }
    }

    cout << w;
}