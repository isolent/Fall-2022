#include <iostream>
#include <vector>
using namespace std;

bool substring_eq(vector<int> &p_pow, vector<int> &h,
                   int i1, int i2, int len) {
     int h1 = h[i1 + len - 1];
     if (i1) h1 -= h[i1 - 1];
     int h2 = h[i2 + len - 1];
     if (i2) h2 -= h[i2 - 1];

     return (i1 < i2 && (h1 * p_pow[i2 - i1]) == h2) ||
            (i1 > i2 && h1 == (h2 * p_pow[i1 - i2]));
 }

 void find_hashes(string &s, vector<int> &p_pow, vector<int> &h) {
    int p = 31;
     p_pow[0] = 1;
     for (size_t i = 1; i < p_pow.size(); ++i) {
         p_pow[i] = p_pow[i - 1] * p;
     }

     for (size_t i = 0; i < s.length(); ++i) {
         h[i] = (s[i] - 'A' + 1) * p_pow[i];
         if (i) h[i] += h[i - 1];
     }
 }

int solve(string &s) {
     vector<int> p_pow(s.length()), hashes(s.length());

     find_hashes(s, p_pow, hashes);

     int cycle_len = s.length();
     for (int k = 1; k < s.length(); ++k) {
         if (substring_eq(p_pow, hashes, 0, k, s.length() - k)) {
             cycle_len = k;
             break;
         }
     }
     return cycle_len;
 }

 int main() {
    
     string s;
     cin >> s;

     cout << solve(s) << endl;
     return 0;
 }