#include<bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i = 8; i >= 0; --i){
        cout << ((num>>i)&1) ;
    }
    cout << endl;
}
int main() {
    for(int i = 0; i < 8; i++)
        printBinary(i);
}

/* output

00000000
00000001
00000010
00000011
00000100
00000101
00000110
00000111
00001000

*/
