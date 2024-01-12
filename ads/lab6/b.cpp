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

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> v1;
    vector <int> v2;
    
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        v1.push_back(x);
    }

    for (int j = 0; j < m; ++j){
        int x; cin >> x;
        v2.push_back(x);
    }

    q_sort(v1, 0, v1.size() - 1);
    q_sort(v2, 0, v2.size() - 1);

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (v2[i] == v1[j]){
                cout << v2[i] << " ";
                v1[j] = -11111;
                break;
            }
        }
    }
}