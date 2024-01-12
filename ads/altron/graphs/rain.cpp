#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main(){
    int k = 0;
    vector<int> t;
    vector <vector<int> > a;
    int n, bb;
    vector<int> b;
    cin >> n;
    for(int i = 0; i < n; ++i){
        t.clear();
        for(int j = 0; j < n; ++j){
            cin >> bb;
            t.push_back(bb);
        }
        a.push_back(t);
    }
    cout << endl;
    for(int i = 0; i < n; ++i){
        cin >> bb;
        b.push_back(bb);
        }
    for(int i = 0; i < n - 1; ++i){
        for(int j = i; j < n; ++j)
           if(a[i][j] == 1)
               if(b[i]!=b[j])
                   k++;
    }
    cout << k;
    return 0;
}