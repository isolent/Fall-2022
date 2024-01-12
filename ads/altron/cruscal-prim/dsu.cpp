#include <iostream>
#include <vector>
#include <set>
using namespace std;
int p[100005];

void init(){
    for(int i = 0; i < 1000005; i++){
        p[i] = i;
    }
}

int find(int v){
    if(p[v] == v) return v;
    else 
        return find(p[v]); // like bst, восстанавливали путь до заданной вершины
}

bool merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if (root_a == root_b) return true;
    else{
        p[root_a] = root_b;
        return false;
    }
}


int main(){
    init();
    merge(1,2); 
    merge(3,4); 
    merge(5,6); 
    merge(4,5); 
    merge(4,5); 
    merge(1,3); 
    merge(1,2); 
    for(int i = 1; i<=6; i++){
        cout << p[i] << " ";
    }
}