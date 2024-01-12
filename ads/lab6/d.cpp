#include <iostream>
#include <vector>
using namespace std;

bool compare(string date1, string date2){
	string day1 = date1.substr(0, 2);
	string month1 = date1.substr(3, 2);
	string year1 = date1.substr(6, 4);

	string day2 = date2.substr(0, 2);
	string month2 = date2.substr(3, 2);
	string year2 = date2.substr(6, 4);

    if (year1 > year2) return true;
    if (year1 < year2) return false;
    if (month1 > month2) return true;
    if (month1 < month2) return false;
    if (day1 > day2) return true;
    if (day1 < day2) return false;
    return false;
}


int q_partition(vector <string> &v, int l, int r){
    string p = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (compare(p, v[j])){
             ++i;
            swap(v[i], v[j]);

        }
    }
    swap(v[i+1], v[r]);
    return i + 1; 
}

void q_sort(vector <string> &v, int l, int r){
    if (l >= r) return;
    int p = q_partition(v, l, r);
    q_sort(v, l, p - 1);
    q_sort(v, p + 1, r);
}

int main() {
    vector<string> v;
    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        v.push_back(s);
    }
 
    q_sort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
 
    return 0;
}
