#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++) {
        bool flag = false;
        for(int j = 0; j < n - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(flag == false)   
            break;
    }
}


// TC : Bubble Sort	Best : Ω(n)	Average : θ(n^2) Worst : O(n^2)
