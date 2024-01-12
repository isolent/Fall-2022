#include <iostream>
#include <vector>
#include <set>

int a[104][104];

using namespace std;
int main(){
    int n; 
    cin >> n;

    vector <pair <int, int> > v;

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) {
                v.push_back(make_pair(i , j));
            }
        }
    }
    
    cout << n << " " << v.size() << endl;
    for (int i = 0; i < v.size() ; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    
    return 0;
}