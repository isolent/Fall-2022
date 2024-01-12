#include <iostream>
#include <vector>
using namespace std;

vector <int> prefFunc(string s){
    vector <int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j - 1];
        }

        if (s[j] == s[i]){
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }

        if (s[pi[i-1]] == s[i]){
            pi[i] = pi[i - 1];
        }
    }
    return pi;
}

vector <int> kmp(string s, string t){
    s = t + '#' + s;
    vector <int> res;
    vector <int> pi = prefFunc(s);
    for (int i = 0; i < s.size(); i++){
        if (pi[i] == t.size()) {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}

int main (){
    string s, t;
    cin >> s >> t;
    vector <int> res = kmp(s, t);
    for (int i = 0; i < res.size(); i ++){
        cout << res[i] << " " ; 
    }
    
}