/*
Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.

Input:
N = 5
vector = {1, 1, 1, 1, 1}
X = 1
Output: 
5
Explanation: Frequency of 1 is 5.

*/
#include<bits/stdc++.h>
using namespace std;

int findFrequency(vector<int> v, int x){
    // Your code here
    map<int, int> m ;
     for(int i = 0; i < v.size() ; i++){
   // for( auto i : v){
        m[i] += 1;
    }
    return m[x];
}

int main()
{
    int testCase;
    cin >> testCase;

    while(testCase--){
        int N;
        cin >> N;

        vector<int> v;

        // Taking vector element input
        for ( int i = 0 ; i < N ; i++ ){
            int k;
            cin >> k;
            v.push_back(k);
        }

        int x;
        cin >> x;
        cout << findFrequency( v , x ) << endl;
    }

    return 0;
}

