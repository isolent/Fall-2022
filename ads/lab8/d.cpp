#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long MOD = 1e9 + 7;
long long P = 31;
map <int, int> m;

long long getHash(string &s){
    long long hash = 0;
    long long curP = 1;
    for (int i = 0; i < s.size(); i++){
        long long curHash = (s[i] - 'a' + 1) * curP % MOD;
        hash = (hash + curHash) % MOD;
        curP = (curP * P) % MOD;
    }
    return hash;
}

vector <long long> getPrefHash(string &s){
    vector <long long> vec (s.size());
    long long curP = 1;
    for (int i = 0;  i< s.size(); i ++){
        vec[i] = (s[i] - 'a' + 1) * curP % MOD;
        if (i){
            vec[i] = (vec[i] + vec[i-1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return vec;
}


void rabinKarp(string &s, pair<string, int> &t, int &maxi){
    if(t.first.size() > s.size()) return;
    long long smallHash = getHash(t.first);
    vector <long long> hashes = getPrefHash(s);
    for (int i = 0; i < s.size() - t.first.size() + 1; i ++){
        long long diff = hashes[i + t.first.size() - 1];
        if(i) diff -= hashes[i-1]; 
        if(diff < 0) diff += MOD;
        if(i) smallHash = (smallHash * P) % MOD ;
        if(smallHash == diff) {
            t.second++;
            maxi = max(maxi, t.second);
        }
    } 
}

int main(){
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        pair<string, int> words[n];
        for (int i = 0; i < n; i++){
            cin >> words[i].first;
            words[i].second = 0;            
        }
        string s;
        cin >> s;
        int maxi = -1;
        for (int i = 0; i < n; i ++){
            rabinKarp(s, words[i], maxi);
        }

        cout << maxi << endl;
        for (int i = 0; i < n; i++){
            if(words[i].second == maxi){
                cout << words[i].first << endl;
            }
        }
    }
}