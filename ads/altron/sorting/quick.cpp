#include <iostream>
using namespace std;

int q_partition(int a[], int l, int r) {
  int p = a[r];
  int i = l - 1;
  for (int j = l; j < r; ++j) {
    if (a[j] < p) {
      ++i;
      swap(a[i], a[j]);
    }
  }
  swap(a[i+1], a[r]);
  return i + 1;
} 

void q_sort(int a[], int l, int r) {
  if (l >= r) return;
  int p = q_partition(a, l, r);
  q_sort(a, l, p - 1);
  q_sort(a, p + 1, r);
}

int main() {

  int n;
  cin >> n ;
  int a[n];

  for (int i = 0; i < n; ++i) cin >> a[i];
  

//   for (int i = 0; i < m; ++i) cin >> b[i];

  q_sort(a, 0, n - 1);
//   q_sort(b, 0, m - 1);

  for (int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
//   cout << endl;
//   for (int i = 0; i < n; i++){
//     cout << b[i] << " ";
//   }
  
}