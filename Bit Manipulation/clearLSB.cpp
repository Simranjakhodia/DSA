// https://www.youtube.com/watch?v=XjtYsFjXtoE&list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV&index=5   19:08

// CLEAR ALL LSB'S TILL i-th BIT

#include<bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for(int i = 10; i >= 0; i--) {
        cout << ((num >> i)&1);
    }
    cout << endl;
}

int main() {
    printBinary(59);
    int a = 59;
    int i = 4;  // unset all bits til 4th bit
    int b = (a & (~((1 << (i+1))-1)));
    printBinary(b);
}

/* 
00000111011
11111100000 & 
00000011111
00000100000-1 = 00000011111



ans = 00000010000
*/
