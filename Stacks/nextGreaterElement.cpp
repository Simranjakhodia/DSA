
/*
Given an array, print the Next Greater Element (NGE) for
every element. The Next greater Element for an element x is
the first greater element on the right side of x in the array. 
Elements for which no greater element exist, consider the next greater 
element as -1. 

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

*/


#include <bits/stdc++.h>
using namespace std;

void funct(int arr[], int n)
{
    stack <int> s;
    s.push(arr[0]);

    for(int i= 1 ; i < n; i++)
    {
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }

        while(s.empty() == false && s.top() < arr[i]){
            cout << s.top() << "--> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }

    while(s.empty() == false){
         cout << s.top() << "--> " << -1 << endl;
         s.pop();
    }
}

int main()
{
    int arr[] = { 11, 13, 21, 3, 22 };
    int n = sizeof(arr) / sizeof(arr[0]);
    funct(arr, n);
    return 0;
}


// https://www.geeksforgeeks.org/next-greater-element/