#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct side{
    int a, b, price;
};

int n, m, v;
vector <side> s;
bool ok = false;

void solve(){
    vector <int> d(n, INF);
    d[v] = 0;
    vector <int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i){
        x = -1;
        for (int j = 0; j < n * n; ++j){
            if (d[s[j].a] < INF){
                if (d[s[j].b] > d[s[j].a] + s[j].price) {
                    d[s[j].b] = max(-INF, d[s[j].a] + s[j].price);
                    p[s[j].b] = s[j].a;
                    x = s[j].b;
                }
            }
        }
    }
    if (x == -1) ok = false;
    else {
        int y = x;
        for (int i = 0; i < n; i++){
            y = p[y];
        }
        vector <int> path;
        for (int cur = y; ;cur = p[cur]){
            path.push_back(cur);
            if (cur == y and path.size() > 1) break; 
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (size_t i = 0; i < path.size(); ++i){
            cout << path[i] + 1 << " ";
        }
        cout << endl;
        ok = true;
    }
}

int main(){
    cin >> n ;
    vector <int> d(n, INF);

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            side cur;
            cin >> cur.price;
            cur.a = i; cur.b = j;
            s.push_back(cur);
        }
    }

    for (int i = 0; i < n; i++){
        v = i;
        solve();
        if (ok) break;
    }
    if (!ok) {
        cout << "NO" << endl;
    }
}