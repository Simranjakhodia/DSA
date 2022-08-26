//  https://www.geeksforgeeks.org/cpp-program-for-heap-sort/#:~:text=Heap%20sort%20is%20a%20comparison,same%20process%20for%20remaining%20element.

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l < n && arr[l] > arr[largest])
        largest = l;
        
    if(r < n && arr[r] > arr[largest])
        largest = r;
        
    if(largest != i) {
        swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
        
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted Array \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

// TC : O(N log N)  SC : O(N)

