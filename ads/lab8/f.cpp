#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

long long MOD = 1011148561;
long long X = 31;

int main() { 
    string s;
    cin >> s;
    vector<long long> vec(s.size());
    vec[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        vec[i] = (vec[i - 1] * X) % MOD;
    }
    vector<long long> hashes (s.size()+1);
    for (int i = 0; i < s.size(); i++){
        hashes[i+1] = (hashes[i] + (s[i] - 'a' + 1) * vec[i]) % MOD;
    }    
    int ans = 0;
    for (int i = 1; i <= s.size(); ++i) {
        unordered_set<long long> res;
        int k = 1;
        for (int j = 0; j <= s.size() - i; ++j) {
        long long hs = (hashes[j+i]+MOD- hashes[j]) % MOD;
        hs = (hs * vec[s.size()-(j+1)]) % MOD;
        res.insert(hs);
        }
        ans += res.size();
    }
    cout << ans << endl;
}