# include <stdio.h>
# include <iostream>

using namespace std;

void merge ( int * pa , int *ptemp , int low , int high , int highEnd ){
    int lowEnd = high - 1 , l = low , h = high , t = low ; 
    while ( l <= lowEnd && h <= highEnd ){
        if ( pa[l] > pa[h] )
            ptemp [t++] = pa[h++];
        else
            ptemp [t++] = pa[l++];    
    }

    while ( l<= lowEnd ){
        ptemp [t++] = pa [l++];
    }
    while ( h<= highEnd ){
        ptemp [t++] = pa [h++];
    } 

    for ( t = low ; t <= highEnd ; t++ )
    {
        pa [t] = ptemp[t] ;

    }
}

void mergesortHelper( int *pa, int*ptemp,int low, int high ){
    if(low < high){
        int mid = (low + high) / 2;
        mergesortHelper ( pa, ptemp, low, mid );
        mergesortHelper ( pa, ptemp, mid+1, high);
        merge (pa , ptemp , low , mid+1 , high);
    }
}

void mergesort( int *pa , int n){
    int *ptemp = (int*)calloc ( n , sizeof(int));
    mergesortHelper( pa , ptemp , 0 , n-1);
    free(ptemp);
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
    mergesort( arr , n);
    cout << " Sorted array \n" ;
    printArray( 0, n-1, arr );
    return 0;
}
