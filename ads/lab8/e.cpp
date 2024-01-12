#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s = "";
    long long a[n];
    a[0] = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; 
        char f = (((a[i] - a[i-1]) / pow(2, i-1))) + 'a';
        s += f;
    }
    cout << s;
}
