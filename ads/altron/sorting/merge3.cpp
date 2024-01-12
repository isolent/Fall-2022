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

    for(; j  <= r; j++){
        b[k] = a[j];
        k++;
    }

    for (i = l; i <= r; i++){
        a[i] = b[i];
    }
}
void mergeSort(int a[], int l, int r){
    if (l < r){
        int mid = (l + r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergeOne(a, l, mid, r);
    }
}
void mergeTwo(int a[], int b[], int n, int m){
    int i, j, k ;
    i = j = k = 0;
    while(i < n && j < m){
        if (a[i] < b[j]){
            c[k] = a[i];
            k++; i++; 
        } else {
            c[k] = b[j];
            k++; j++;
        }
    }

    for (; i < n; i++){
        c[k] = a[i];
        k++;
    }

    for(; j  < m; j++){
        c[k] = b[j];
        k++;
    }
}

int main(){
    int a[9] = {2, 5, 7, 10, 15, 1, 3, 6, 13};
    mergeOne(a, 0, 2, 7);
    // mergeTwo(a, b, 5, 4);
    for (int i = 0; i < 9; i++){
        cout << c[i] << " ";
    }
}