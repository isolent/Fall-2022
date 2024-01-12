#include <iostream>
using namespace std;

int n, m;
char c[105][105]; 
bool used[105][105];
int d_i[4] = {1, -1, 0, 0};
int d_j[4] = {0, 0, -1, 1};

void dfs(int i, int j) {
    used[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int a = i + d_i[k];
        int b = j + d_j[k];
        if (a >= 0 && a < n && b >= 0 && b < m ) {
            if (c[a][b] == '1' && !used[a][b])
                    dfs(a, b);
                }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && c[i][j] == '1') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}