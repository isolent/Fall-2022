#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int q_partition(vector <int> &v, int l, int r){
    int p = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (v[j] < p){
             ++i;
            swap(v[i], v[j]);

        }
    }
    swap(v[i+1], v[r]);
    return i + 1; 
}

void q_sort(vector <int> &v, int l, int r){
    if (l >= r) return;
    int p = q_partition(v, l, r);
    q_sort(v, l, p - 1);
    q_sort(v, p + 1, r);
}

int main () {
    int n, m;
    cin >> n >> m;
    vector < vector<int> > v(m, vector<int> (n));
    for (int j = 0; j < n; ++j){
        for (int i = 0; i < m; ++i){
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; ++i){
        q_sort(v[i], 0, n - 1);
    }


    for (int i = n - 1; i >= 0; --i){
        for (int j = 0; j < m; ++j){
            cout << v[j][i] << " ";
        }
        cout << endl;
    }
}