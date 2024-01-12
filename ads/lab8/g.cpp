#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long MOD = 1e9 + 9;
long long P = 31;

long long getHash(string & s) {
    long long hash = 0;
    long long curP = 1;
    for (int i = 0; i < s.size(); i ++){
        long long curHash = (s[i] - 'a' + 1) * curP % MOD;
        hash = (hash + curHash) % MOD;
        curP = (curP * P) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string & s) {
    long long curP = 1;
    vector<long long> vec(s.size());
    for (int i = 0; i < s.size(); i++){
        vec[i] = (s[i] - 'a' + 1) * curP % MOD;
        if (i){
            vec[i] = (vec[i] + vec[i - 1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return vec;
}

int rabinKarp(string & s, string & t, vector<long long> & vec) {
    int ans = 0;
    long long hashSm = getHash(t);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long diff = vec[i + t.size() - 1];
        if(i) diff -= vec[i - 1];
        if (diff < 0) diff += MOD;
        if (i) hashSm = (hashSm * P) % MOD;
        if (hashSm == diff){
            ans++;
        }
    }
    return ans;
}


int main() {
    string s;
    cin >> s;
    vector<long long> vec = getPrefixHashes(s);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        string tmp = "";
        for (int i = l; i < r; i ++){
            tmp += s[i];
        }
        cout << rabinKarp(s, tmp, vec) << endl;
    }
}