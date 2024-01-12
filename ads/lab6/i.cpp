#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int q_partition(vector <char> &v, int l, int r){
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

void q_sort(vector <char> &v, int l, int r){
    if (l >= r) return;
    int p = q_partition(v, l, r);
    q_sort(v, l, p - 1);
    q_sort(v, p + 1, r);
}

int main(){
    string s; cin >> s;
    vector <char> v;
    for (int i = 0; i < s.size(); ++i){
        v.push_back(s[i]);
    }
    q_sort(v, 0, v.size() - 1);

    for(int i = 0; i < v.size(); ++i){
        cout << v[i] ;
    }
}
