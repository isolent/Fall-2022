#include <iostream>
#include <vector>
using namespace std;
vector <int> prefix_function (string s) {
	int n = (int) s.length();
	vector <int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;

}

int main(){
    string s;
    cin >> s;
    vector <int> p = prefix_function(s);
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
}