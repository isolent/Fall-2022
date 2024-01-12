#include <iostream>
#include <vector>
using namespace std;

vector <pair <vector <int>, int > > res;


int main(){
    int n; cin >> n;

    int n, m; cin >> n >> m;
    vector < vector<int> > v(m, vector<int> (n));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            sum += v[i][j];
        }
        res.push_back(make_pair(v[i], sum));
        sum = 0;
    }
    
    for (int i = 0; i < n; i++){
        
    }
}