/*
Given a list of N words. Count the number of words that appear exactly twice in the list.

Input:
N = 3
list = {Geeks, For, Geeks}
Output: 1
Explanation: 'Geeks' is the only word that 
appears twice. 

*/



#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int countWords(string list[], int n)
        {
            map<string , int > m;
            int c = 0 ;
            int i;
            for( i = 0 ; i < n ; i++ ){
                m[list[i]] ++;
            }
            for(auto j : m){
                if(j.second == 2)
                    c++;
            }
            return c;
        }
    
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string list[n];
        for(int i = 0 ; i < n ; i++)
            cin >> list[i];
        Solution ob;
        cout << ob.countWords(list, n ) << endl;   
    }

    return 0; 

}


// https://practice.geeksforgeeks.org/problems/twice-counter/0