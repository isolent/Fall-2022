#include <iostream>
#include <vector>
using namespace std;

vector < vector <int> > v(111);

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
    }
   
    cout << n << endl;

    for(int i = 0; i < n; i++) {
        
        cout << v[i].size() << " ";
        
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}