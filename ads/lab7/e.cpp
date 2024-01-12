#include <iostream>
#include <vector>
using namespace std;

struct Row{
    int sum;
    vector <int> v;

    Row(){
        this->sum = 0;
    }

    void add(int x){
        this->sum += x;
        this->v.push_back(x);
    }

    void print(){
        for(int i = 0; i < this->v.size(); i++){
            cout << this->v[i] << " ";
        }
        cout << endl;
    }

    bool compare(Row * v2){
        if(this->sum > v2->sum)
            return true;
        if(this->sum == v2->sum){
            for(int i = 0; i < this->v.size(); i++){
                if(this->v[i] != v2->v[i]){
                    return this->v[i] < v2->v[i];
                }
            }
            return false;
        }
        return false;
    }
};

void merge(Row * a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    Row v[n1]; 
    for(int i = 0; i < n1; ++i){
        v[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    Row v2[n2];
    for(int i = 0; i < n2; ++i){
        v2[i] = a[l2 + i];
    }
    int i = l1;
    int i1 = 0, i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(v[i1].compare(&v2[i2])){
            a[i] = v[i1];
            i++; i1++;
        } else {
            a[i] = v2[i2];
            i++; i2++;
        }
    }
    
    while(i1 < n1){
        a[i] = v[i1];
        i++; i1++;
    }
    
    while(i2 < n2){
        a[i] = v2[i2];
        i++; i2++;
    }
    
}

void sort(Row * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main(){
    int n, m, x;
    cin >> n >> m;

    Row rows[n];

    for(int i =0; i < n;i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            rows[i].add(x);
        }
    }

    sort(rows, 0, n - 1);

    for(int i = 0; i < n; i++){
        rows[i].print();
    }

    return 0;
}