#include<bits/stdc++.h>
using namespace std;

long long karatsuba(long long x, long long y)
{
    
    
    if(x < 10 || y < 10)
    return x*y;

    int n = min(log10(x)+1, log10(y)+1) ;  // min length
    int m = floor(n/2) ; 
    long long xl = floor(x / pow(10, m));
    long long xr = x % (int)(pow(10, m));

    long long yl = floor(y / pow(10, m));
    long long yr = y % (int)(pow(10, m));

    long long p1 = karatsuba( xl, yl );
    long long p3 = karatsuba( xr, yr );
    long long p2 = karatsuba( xl+xr , yl+yr ) - p1 - p3 ;
 //   long long solution = p1*( pow(10, n)) + p2*( pow(10, m)) + p3 ;  
    return (long long)(p1*( pow(10, n)) + p2*( pow(10, m)) + p3);
}

int main()
{
    long long a , b;
    cout << "Enter two large nos for Karatsuba Multiplication" << endl;
    cin >>  a >>  b ; 
    cout << "The result of Large No. Multiplication is : " << karatsuba( a , b ) <<endl;

    return 0;
}