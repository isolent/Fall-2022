#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student{
    string name, surname;
    double gpa;
};

bool cmp(Student s1, Student s2){
    if (s1.gpa == s2.gpa){
        if (s1.name == s2.name){
            return s1.surname > s2.surname;
        } else {
            return s1.name > s2.name; 
        }
    }
    return s1.gpa > s2.gpa;
}
void MergeOne(vector<Student> &v, int l, int mid, int r){
    int i, j;
    i = l;
    j = mid+1;
    vector <Student> b;
    while(i <= mid && j <= r){
        if(!cmp(v[i], v[j])){   
            b.push_back(v[i]);
            i++;
        } else {
            b.push_back(v[j]);
            j++;
        }
    }
    for(; i <= mid; i++){
        b.push_back(v[i]);
    }

    for(; j <= r; j++){
        b.push_back(v[j]);
    }

    for(i = l; i <= r; i++){
        v[i] = b[i-l];
    }

}

void merge(vector<Student> &v, int l, int r){
    if(l<r){
        int m=(l+r)/2;
        merge(v, l, m);
        merge(v, m+1, r);
        MergeOne(v, l, m, r);
    }
}

double gpaNum(string s){
    if(s == "A+") return 4.00;
    if(s == "A") return 3.75;
    if(s == "B+") return 3.50;
    if(s == "B") return 3.00;
    if(s == "C+") return 2.50;
    if(s == "C") return 2.00;
    if(s == "D+") return 1.50;
    if(s == "D") return 1.00;
    if(s == "F") return 0;
    else return -1;
}


int main() {
    int n; cin >> n;
    vector <Student> v(n);
    int m;
    for (int i = 0; i < n; i++){
        cin >> v[i].name >> v[i].surname >> m;
        double allCredits = 0;
        double sum = 0;
        for (int j = 0; j < m; j++){
            string s;
            int credits;
            cin >> s >> credits;
            allCredits += credits;
            sum += gpaNum(s) * credits;
        }
        v[i].gpa = sum / allCredits;
    }

    merge(v, 0, v.size() - 1);
    for (int i = 0; i < n; i++){
        cout << v[i].name << " " << v[i].surname << " "
        << fixed << setprecision(3) << v[i].gpa << endl;
    }
}