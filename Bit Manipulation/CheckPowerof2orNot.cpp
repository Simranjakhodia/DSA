#include<bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for(int i = 10; i >= 0; i--) {
        cout << ((num >> i)&1);
    }
    cout << endl;
}

int main() {
    int n = 16;
    if(n & (n-1) != 0)
        cout << "Not a power of 2" << endl;
    else 
        cout << "Power of 2" << endl;
}



