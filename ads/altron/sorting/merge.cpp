#include <iostream>
using namespace std;
int c[10000003];
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
    int a[5] = {2, 5, 7,  10, 15};
    int b[4] = {1, 3, 6,  13};
    mergeTwo(a, b, 5, 4);
    for (int i = 0; i < 9; i++){
        cout << c[i] << " ";
    }
}