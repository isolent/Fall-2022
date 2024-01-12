#include <iostream>
#include <vector>
#include <string>
using namespace std;

int c[10000003];

bool cmp (string &s, string &t){
    return s.size() > t.size();
}
void mergeOne(vector <string> &v, int l, int mid, int r){
    int i, j;
    i = l;
    j = mid + 1;
    // k = l;
    vector <string> b;
    while(i <= mid && j <= r){
        if (cmp(v[i], v[j])){
            b.push_back(v[j]);
            j++; 
        } else {
            b.push_back(v[i]);
            i++;
        }
    }
    for (; i <= mid; i++){
        b.push_back(v[i]);

    }

    for(; j <= r; j++){
        b.push_back(v[j]);
    }

    for (i = l; i <= r; i++){
        v[i] = b[i - l];
    }
}


void merge(vector <string> &v, int l, int r){
    if (l < r){
        int m = (l + r)/2;
        merge(v, l, m);
        merge(v, m + 1, r);
        mergeOne(v, l, m, r);
    } 
}

int main() {
    int n; 
    cin >> n;
    for (int k = 1; k <= n; k++){
        string s;
        getline(cin >> ws, s);
        vector <string> v;
        string cur = "";
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == ' '){
                v.push_back(cur);
                cur = "";
                continue;
            }
            cur += s[i];
        }
        v.push_back(cur);
        
        merge(v, 0, v.size()-1);
        for (int i = 0; i < v.size(); i ++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}