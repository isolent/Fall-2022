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

int q_partition(vector <Student> &v, int l, int h){
    Student p = v[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++){
        if (cmp(p, v[j])){
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[h]);
    return i + 1;
}

void q_sort(vector <Student> &v, int l, int h){
    if (l < h){
        int p = q_partition(v, l, h);
        q_sort(v, l, p - 1);
        q_sort(v, p + 1, h);
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

    q_sort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++){
        cout << v[i].name << " " << v[i].surname << " "
        << fixed << setprecision(3) << v[i].gpa << endl;
    }
}