#include <iostream>
using namespace std;

int c[10000003];

void mergeOne(int a[], int l, int mid, int r){
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[r + 1];
    while(i <= mid && j <= r){
        if (a[i] < a[j]){
            b[k] = a[i];
            k++; i++; 
        } else {
            b[k] = a[j];
            k++; j++;
        }
    }
    for (; i <= mid; i++){
        b[k] = a[i];
        k++; 
    }

    for(; j <= r; j++){
        b[k] = a[j];
        k++;
    }

    for (i = l; i <= r; i++){
        a[i] = b[i];
    }
}


void merge(int a[], int l, int r){
    if (l < r){
        int m = (l+r)/2;
        merge(a, l, m);
        merge(a, m + 1, r);
        mergeOne(a, l, m, r);
    } 
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int j = 0; j < m; j++){
        cin >> b[j]; 
    }
    merge (a, 0, n - 1);
    merge (b, 0, m - 1);
    int i = 0;
    int j = 0;
    while (i < n and j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            ++i; ++j;
        } else if (a[i] < b[j]) {
            ++i;
        } else ++j;
    }
}