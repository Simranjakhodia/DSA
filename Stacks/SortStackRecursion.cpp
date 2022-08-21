#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int x) {
    if(s.size() == 0 || s.top() <= x) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}

void sort(stack<int>& s) {
    if(s.size() == 1) 
        return;
    
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
}
void printStack(stack<int>& s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
int main() {
    stack<int> s;
    s.push(5);
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(4);
    sort(s);
    printStack(s);
}


/// https://www.youtube.com/watch?v=MOGBRkkOhkY&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=7&ab_channel=AdityaVerma
