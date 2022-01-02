// https://www.youtube.com/watch?v=XjtYsFjXtoE&list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV&index=5     at 9:38

#include<bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i = 8; i >= 0; --i){
        cout << ((num>>i)&1) ;
    }
    cout << endl;
    
}

int main() {
    for(char c = 'A'; c <= 'E'; c++){
        cout << c << " ";
        printBinary(int(c));
    }
    for(char c = 'a'; c <= 'e'; c++){
        cout << c << " ";
        printBinary(int(c));
    }
    
    /* To convert 'A' into 'a', set the 5th bit while 
        to convert 'a' into 'A', unst the 5th bit */
    cout << endl;
    char A = 'A';
    char a = A |(1<<5);
    cout << A << "converted to " << a << endl;
    cout << a << "converted to " << char(a & (~ (1 << 5))) << endl;
    return 0; 
}
