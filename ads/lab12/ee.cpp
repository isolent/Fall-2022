#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
  int a, b, cost;
  edge(int v, int u, int w) {
    this -> a = v;
    this -> b = u;
    this -> cost = w;
  }
};

int n;
const int INF = 1000000000;
vector<edge> e;

void solve() {
  vector<int> d(n, 1000000000);
  vector<int> p(n, -1);
  int x;

  for (int i = 0; i < n; ++i) {
    x = -1;
    for (int j = 0; j < e.size(); ++j) {
      if (d[e[j].b] > d[e[j].a] + e[j].cost) {
        d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
        p[e[j].b] = e[j].a;
        x = e[j].b;
      }
    }
  }

  if (x == -1) cout << "NO" << endl;
  else {
    int y = x;
    for (int i = 0; i < n; ++i) y = p[y];
    vector<int> path;

    for (int cur= y; ; cur = p[cur]) {
      path.push_back(cur);
      if (cur == y and path.size() > 1) break;
    }
    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
      cout << path[i] + 1 << " ";
    }

  }

}

int main() {

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x; cin >> x;
      if (x < 100000) e.push_back(edge(i, j, x));
    }
  }
  solve();

}