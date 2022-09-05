// https://www.youtube.com/watch?v=88k8xa-pSrM&ab_channel=AlgorithmsMadeEasy

// https://leetcode.com/problems/kth-missing-positive-number/submissions/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int missing = compute(arr[n-1], n);
        while(left <= right) {
            int mid = left + (right - left)/2;
            missing = compute(arr[mid], mid+1);
            
            if(missing >= k) right = mid - 1;
            else left = mid + 1;
        }
        if(right == -1) return k;
        return arr[right] + k - compute(arr[right], right+1);
    }
    int compute(int actual, int expected) {
        return actual - expected;
    }
};


