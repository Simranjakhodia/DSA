int binarySearch(vector<int>& v, int key) {
    int l = 0, h = 1;
    int val = v[0];
    while(val < key) {
        l = h;
        h = 2*h;
        val = arr[h];
    }
    return helper(v, l, h, key);
}

int helper(vector<int>& v, int l, int h, int key) {
    while(l <= h) {
        int mid = l + (h - l)/2;
        if(v[mid] == key)
            return mid;
        if(v[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}


// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
