#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix_function(string s) {
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }
    return pi;
}

// vector<int> kmp(string s, string t) {
//     s = t + '#' + s;
//     vector<int> res;
//     vector<int> pi = prefix_function(s);
//     for (int i = 0; i < s.size(); i++) {
//         if (pi[i] == t.size()) {
//             res.push_back(i - 2 * t.size());
//         }
//     }
//     return res;
// }

int main() {
    string s;
    cin >> s;
    vector <int> res = prefix_function(s);
    cout << s.size() - res[res.size() - 1];
}