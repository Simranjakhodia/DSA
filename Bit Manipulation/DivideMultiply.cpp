#include<bits/stdc++.h>
using namespace std;

int main() {
  int num = 5;
  
  // to get 5/2 using bit-wise do rightshift:
  cout << "5/2 = " << (num >>1) <<endl;
  
  //to get 5*2 using bit-wise do leftshift:
  cout << "5*2 = " << (num << 1) << endl;
  
  return 0;
} 
