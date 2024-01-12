#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[1005][1005];

    bool used[1005][1005];
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1) {
                used[i][j] = true;
            }
        }
    }

    for(int i = 0; i < q; i++){
        int d, b, c;
        cin >> d >> b >> c;
        if (a[d][b] && a[b][c] && a[d][c]){
            cout << "YES" << endl;
        } 
        else cout << "NO" << endl;   
    }

    // cout << endl;
    // for (int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << used[i][j] << " ";
    //     }
    //      cout << endl;
    // }
}