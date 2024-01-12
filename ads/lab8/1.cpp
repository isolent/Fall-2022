#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> prefHash(string s) {
    vector<long long> hash(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hash[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hash[i] = (hash[i] + hash[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<int> RK(string s, string t) {
    long long hashS = getHash(t);
    vector<int> res;
    vector<long long> hash = prefHash(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long diff = hash[i + t.size() - 1];
        if (i != 0) diff -= hash[i - 1];
        if (diff < 0) diff += MOD;
        if (i != 0) hashS = (hashS * X) % MOD;
        if (hashS == diff) {
            res.push_back(i);
        };
    }
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> res = RK(s, t);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}