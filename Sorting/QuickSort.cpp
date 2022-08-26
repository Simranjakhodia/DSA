# include <stdio.h>
# include <iostream>

using namespace std;

void quicksortHelper( int *pa , int low, int high );
int partition ( int *pa , int l , int h );
void swap ( int *a , int *b );
void printArray( int low , int high , int *pa );


void quicksort ( int *pa, int n)
{
    quicksortHelper( pa , 0 , n-1 );
}

void quicksortHelper( int *pa , int low, int high ){
    
    if( low < high )
    {
        int pivotIndex = partition ( pa , low , high );
        cout <<"\nPivot is : "<< pa[pivotIndex]<<"\n";
        quicksortHelper ( pa , low , pivotIndex );
        quicksortHelper ( pa , pivotIndex + 1 , high );
    }
}

int partition ( int *pa , int l , int h )
{
    int pivot = pa [ (l + h) / 2 ];  // pivot is taken as mid element for best case

    while ( l <= h )
    {
        while ( pa [l] < pivot )
            l++ ; 
        while ( pa[h] > pivot )
            h-- ; 
        if ( l >= h)
            return h ;        
    

    swap ( & pa[l] , & pa[h]);
    cout << l << " " << h <<"\n";
    printArray( l , h , pa );
    cout <<"\n";
    }
}


void swap ( int *a , int *b )
{
    int t = *a;
    *a = *b ; 
    *b = t;
}

void printArray( int low , int high , int *pa )
{
    for ( int l = low ; l <= high ; l++ )
        cout << pa[l] << "  ";

}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort( arr , n);
    cout << " Sorted array \n" ;
    printArray( 0, n-1, arr );
    return 0;
}


/////



#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[(start + end) / 2];
    while(start <= end) {
        while(arr[start] < pivot) 
            start++;
        while(arr[end] > pivot)
            end--;
        if(start >= end)
            return end;
            
        swap(arr[start], arr[end]);
    }
}
void quickSort(int arr[], int start, int end) {
    if(start >= end) 
        return;
        
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}
int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;
    quickSort(arr, 0, n-1);
    
    for(int i = 0; i < n; i++) 
        cout << arr[i]  << " ";
    
    return 0;
}
