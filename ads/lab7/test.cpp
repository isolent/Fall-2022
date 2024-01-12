// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int n, m; cin >> n >> m;
//     vector < vector<int> > v(m, vector<int> (n));
//     for(int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cin >> v[i][j] ;
//         }
//     }
//     int sum = 0;
//     vector <int> each;
//     for(int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             sum += v[i][j];
//             each.push_back(sum);
//         }
//     }

//     for(int i =0; i < each.size(); i++){
//         cout << each[i] << " ";
//     }
// }
#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long MOD = 1e9 + 7;
long long P = 31;
map <int, int> m;
int ans;

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
    vector <long long> hashes (s.size());
    long long curP = 1;
    for (int i = 0;  i< s.size(); i ++){
        hashes[i] = (s[i] - 'a' + 1) * curP % MOD;
        if (i){
            hashes[i] = (hashes[i] + hashes[i-1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
}

void rabinKarp(string &s, string &t){
    if(t.size() > s.size())return;
    long long hashSm = getHash(t);
    vector <long long> hashes = getPrefHash(s);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long diff = hashes[i + t.size() - 1];
        if(i) diff -= hashes[i-1]; 
        if(diff < 0) diff += MOD;
        if(i) hashSm = (hashSm * P) % MOD ;
        if(hashSm == diff) {
            if(m.find(i) != m.end()){
                ans++;
            }
            m[i] = 1;
        }
    } 
}

int main(){
    string s, t, v;
    cin >> s >> t >> v;
    rabinKarp(s, v);
    rabinKarp(t, v);
}