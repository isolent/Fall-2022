#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long MOD = 1e9 + 7;
long long P = 31;
map <int, int> m;
int ans = 0;

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

void rabinKarp(string &s, string &t){
    if(t.size() > s.size()) return;
    long long smallHash = getHash(t);
    vector <long long> hashes = getPrefHash(s);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long diff = hashes[i + t.size() - 1];
        if(i) diff -= hashes[i-1]; 
        if(diff < 0) diff += MOD;
        if(i) smallHash = (smallHash * P) % MOD ;
        if(smallHash == diff) {
            if (m.find(i) != m.end()){
                ans++;
            } 
            m[i] = 1;
        }
    } 
}

int main(){
    string s, t, u;
    cin >> s >> t >> u; 
    rabinKarp(s,u);
    rabinKarp(t,u);
    cout << ans;
}