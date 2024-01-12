#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<unsigned long long, bool> used;
map<unsigned long long, unsigned long long> mpp;

void bffs(int x, int y){
    queue <unsigned long long> q;
    q.push(x);
    used[x] = true;
    while(!q.empty()){
        unsigned long long b = q.front();
        q.pop();
        if(!used[2*b] && b < y){
            q.push(2*b);
            used[2*b] = true;
            mpp[2*b] = b;
            if(2*b == y)return;
        }
        if(b - 1 > 0 && !used[b - 1]){
            q.push(b - 1);
            used[b - 1] = true;
            mpp[b - 1] =  b;
            if(b - 1 == y)return;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n == m){
        cout << 0;
        return 0;
    } else if (n > m){
        cout << n - m << endl;
        n -= 1;
        while(n != m){
            cout << n << " ";
            n -= 1;
        }
        cout << m;
        return 0;
    }
    bffs(n, m);
    vector <unsigned long long> res;
    while(m != n){
        res.push_back(m);
        m = mpp[m];
    }
    
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
}