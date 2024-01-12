#include <iostream>
#include <vector>
#include <map>
using namespace std;


bool comp(pair <string, string> p1 ,pair < string, string > p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int partition(vector<pair <string, string> > &a, int l, int h){
    int p = h;
    int i = l;
    for (int j = l; j <= h - 1; j++){
        if (comp(a[j], a[p])){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[h]);
    return i;
}

void quicksort(vector<pair <string, string> > &a,int l,int r){
    if(l<r){
        int p=partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main(){
    int n; cin >> n;
    map <string, string> mp;

    string s1, s2;
    vector <pair <string, string> > v;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;
        bool ok = false;
        for(int j = 0; j < v.size(); j++){
            if(s1 == v[j].second){
                v[j].second = s2;
                ok = true;
            }
        }
        if(!ok) v.push_back(make_pair(s1, s2));

    }
    quicksort(v, 0, v.size() - 1);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}