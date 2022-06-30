#include<bits/stdc++.h>
using namespace std;

void build(int arr[], int seg[], int s, int e, int idx) {
    if(s == e) // leaf node 
    {
        seg[idx] = arr[s];
        return;
    }
    int mid = (s + e)/2;
    build(arr, seg, s, mid, 2*idx+1);
    build(arr, seg, mid+1, e, 2*idx+2);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}
int query(int s, int e, int ql, int qr, int seg[], int idx) {
    // no overlap
    if(qr < s || ql > e) return INT_MAX;
    // complete overlap
    if(ql <= s && qr >= e) return seg[idx];
    int mid = (s + e)/2;
    int left = query(s, mid, ql, qr, seg, 2*idx+1);
    int right = query(mid+1, e, ql, qr, seg, 2*idx+2);
    return min(left, right);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int seg[4*n];
    build(arr, seg, 0, n-1, 0);
    //cout << seg[0] << endl;
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(0, n-1, l, r, seg, 0) << endl;
    }
    return 0;
}

/*

Test Case : 

6
1 3 2 7 9 11
3
0 2
1 5
3 5

*/

// https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
