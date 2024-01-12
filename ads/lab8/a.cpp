#include <iostream>
#include <vector>
#include <map>
using namespace std;

int MOD = 1e9 + 7;

string findHash(string s){
    long long p = 1;
    long long r = 0;
    for(int i = 0; i < s.size(); i++){
        r += ((s[i]-47) * p) % MOD;
        p %= MOD; 
        p *= 11;
    }
    return to_string(r % MOD);
}

int main(){
    vector <string> v;
    int n; 
    cin >> n;
    map<string, bool> m;
    for(int i = 0; i < 2*n; i++){
        string s; cin >> s;
        v.push_back(s);
        m[s] = true;
    }
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        string s = findHash(v[i]);
        if(m[s]){
            cout << "Hash of string \"" << v[i] <<  "\" is " << s << endl;
            cnt++;
        }
        if(cnt == n) return 0;
    }
    return 0;
}