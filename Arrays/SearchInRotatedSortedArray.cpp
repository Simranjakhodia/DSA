// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[0] <= nums[mid]) {
                if(nums[0] <= target && target < nums[mid])
                    hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if(nums[mid] < target && target <= nums[n-1])
                    lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/1669196/100-Faster-or-One-pass-Solution-or-C%2B%2B-or-O(LogN)
