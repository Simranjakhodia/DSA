#include<bits/stdc++.h>
using namespace std;

void f(int& p, int& a) {
    p = 5;
    swap(p, a);
}

int help() {
    int a = 10;
    int &p = a;
    cout << "p = " << p<< endl;
    //cout << "*p = " << p << endl;
    cout << "&p = " << &p << endl;
     cout << "&a = " << &a << endl;
     cout << "after changes\n" ;
    f(p, a);
    cout << "p = " << p<< endl;
    //cout << "*p = " << p << endl;
    cout << "&p = " << &p << endl;
    cout << "&a = " << &a << endl;
    
    cout << "a = " << a << endl;
    return 0;
}
void swap(int *xp, int *yp) {
    cout << "In swap function \n\n";
     cout << "&xp = " << &xp << endl;
    cout << "&yp = " << &yp << endl;
    cout << "xp = " << xp << endl;
    cout << "yp = " << yp << endl;
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
     cout << "After swap \n\n";
    cout << "&xp = " << &xp << endl;
    cout << "&yp = " << &yp << endl;
    cout << "xp = " << xp << endl;
    cout << "yp = " << yp << endl;
    cout << "\n\n\nOut swap function \n\n";
}
int main() {
    int x = 2, y = 5;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    swap(&x, &y);
    cout << x << " " << y << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    return 0;
}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Output:

&x = 0x7ffc597968e0
&y = 0x7ffc597968e4
In swap function 

&xp = 0x7ffc597968a8
&yp = 0x7ffc597968a0
xp = 0x7ffc597968e0
yp = 0x7ffc597968e4
After swap 

&xp = 0x7ffc597968a8
&yp = 0x7ffc597968a0
xp = 0x7ffc597968e0
yp = 0x7ffc597968e4



Out swap function 

5 2
&x = 0x7ffc597968e0
&y = 0x7ffc597968e4

  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

