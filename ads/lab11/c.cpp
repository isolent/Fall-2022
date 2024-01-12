#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, pair <int, int > > > sides;
int pp[100005];
int rk[100005];

void dsu(){
    for(int i = 0; i < 100005; i++){
        pp[i] = i;
        rk[i] = 1;
    }
}

int root(int v){
    if (pp[v] == v){
        return v;
    } else return pp[v] = root(pp[v]);
}

bool merge(int a, int b){
    int rootof_a = root(a);
    int rootof_b = root(b);
    if (rootof_a == rootof_b) return false;
    else {
        if (rk[rootof_a] < rk[rootof_b]){
            pp[rootof_a] = rootof_b;
        } else if (rk[rootof_b] < rk[rootof_a]){
            pp[rootof_b] = rootof_a; 
        } else {
            pp[rootof_a] = rootof_b;
            rk[rootof_b] += 1;
        }
        return true;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= m; i++){
        string s; 
        int x, y, z;
        cin >> s >> x >> y >> z;
        if (s == "big") {
            sides.push_back(make_pair(a * z, make_pair(x, y)));
            sides.push_back(make_pair(a * z, make_pair(y, x)));
        } else if (s == "small") {
            sides.push_back(make_pair(b * z, make_pair(x, y)));
            sides.push_back(make_pair(b * z, make_pair(y, x)));
        } else {
            int mn = min(a,b);
            sides.push_back(make_pair(z * mn, make_pair(x, y)));
            sides.push_back(make_pair(z * mn, make_pair(y, x)));
        }
    }

    sort(sides.begin(), sides.end());
    int weight = 0;
    
    dsu();

    for (int i = 0; i < sides.size(); i++){
        if (merge(sides[i].second.first, sides[i].second.second)){
            weight += sides[i].first;
        }
    }

    cout << weight;
}