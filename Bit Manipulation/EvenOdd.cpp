#include<bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i = 8; i >= 0; --i){
        cout << ((num>>i)&1) ;
    }
    
}

void printEvenOdd(int nums) {
    if(nums & 1 != 0)
        cout << "odd";
    else cout << "even"; 
    
    cout << endl;
        
}
int main() {
    for(int i = 0; i < 8; i++){
        printBinary(i);
        printEvenOdd(i);
    }
    return 0;
}
