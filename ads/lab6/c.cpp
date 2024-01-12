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
    int n;
    cin >> n;
    vector <int> v;
    
    for (int i = 0; i < n; ++ i){
        int x; cin >> x;
        v.push_back(x);
    }

    q_sort(v, 0, v.size() - 1);
    vector <pair<int,int> > ans;
    int mn = abs(v[0] - v[1]);
    for (int i = 1; i < n; i ++){
        if (abs(v[i] - v[i - 1]) < mn){
            mn = abs(v[i] - v[i - 1]);
        }
    }

    for (int i = 0; i < n - 1; i ++){
        if (abs(v[i] - v[i + 1]) == mn){
            ans.push_back(make_pair(v[i], v[i + 1]));
        }
    }

    vector <pair<int,int> >  :: iterator it;
    for (it = ans.begin(); it != ans.end(); ++it){
        cout << it->first << " " << it->second << " "; 
    }
}