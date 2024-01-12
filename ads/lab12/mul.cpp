#include <iostream>
#include <queue>
  
using namespace std;
 void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
    cout << '\n';
}
  
// Driver Code
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.emplace(2);
    q1.push(3);
  
    cout << "The first queue is : ";
    print_queue(q1);
}