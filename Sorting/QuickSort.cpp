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
