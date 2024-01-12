#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
    string prev; 
    cin >> prev;
    prev[0] = tolower(prev[0]);
    
    int n; 
    cin >> n;
    
    vector <string> res;
    int mx = 1;        
    
    for(int i = 0; i < n; i++) {
        string city; 
        cin >> city;
        city[0] = tolower(city[0]);
        
        string t = city + "#" + prev;
        
        vector<int> v = prefix_function(t);
        
        city[0] = toupper(city[0]);

        if(v[v.size() - 1] > mx) {
            mx = v[v.size() - 1];
            res.clear();
            res.push_back(city);
        } 
        else if (v[v.size() - 1] == mx) {
            res.push_back(city);
        }
    }
    
    cout << res.size() << endl;

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
