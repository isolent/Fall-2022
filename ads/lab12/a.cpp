#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
vector<vector<int> > d(505, vector<int> (505, INF));
vector<vector<int> > vv(505, vector<int> (505, INF));
int ans = 0;
vector<int> arr;
int n;

void solve(int k) {
  ans = 0;
  // for (int k = 0; k < arr.size(); ++k) { 
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr.size(); ++j) {
      vv[arr[j]][k] = min(vv[arr[j]][k], vv[arr[j]][arr[i]] + vv[arr[i]][k]);
    }
  }




  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr.size(); ++j) {
      vv[k][arr[j]] = min(vv[k][arr[j]], vv[k][arr[i]] + vv[arr[i]][arr[j]]);
    }
  }

  

  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr.size(); ++j) {
      vv[arr[i]][arr[j]] = min(vv[arr[i]][arr[j]], vv[arr[i]][k] + vv[k][arr[j]]);
      if (vv[arr[i]][arr[j]] < INF and vv[arr[i]][arr[j]] > ans) 
        ans = vv[arr[i]][arr[j]];
    }
  }

}

int main() {

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> d[i][j];
      if (d[i][j] == 0 and i != j) d[i][j] = INF;
      if (i == j) vv[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    int x; 
    cin >> x;
    arr.push_back(x);
    for (int j = 0; j < arr.size(); ++j) {
      vv[x][arr[j]] = d[x][arr[j]];
      vv[arr[j]][x] = d[arr[j]][x];
    } 
    solve(x);
    cout << ans << endl;
  }

  

}