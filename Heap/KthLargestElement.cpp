class KthLargest {
public:
    priority_queue<int, vector<int>, greater <int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
      for(int i = 0 ; i < nums.size(); i++){
          minHeap.push(nums[i]);
          if(minHeap.size() > k)
              minHeap.pop();
      }  
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
// class KthLargest {
public:
    priority_queue<int, vector<int>, greater <int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
      for(int i = 0 ; i < nums.size(); i++){
          minHeap.push(nums[i]);
          if(minHeap.size() > k)
              minHeap.pop();
      }  
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
// class KthLargest {
public:
    priority_queue<int, vector<int>, greater <int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
      for(int i = 0 ; i < nums.size(); i++){
          minHeap.push(nums[i]);
          if(minHeap.size() > k)
              minHeap.pop();
      }  
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
// https://www.youtube.com/watch?v=4BfL2Hjvh8g&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=2

// https://leetcode.com/problems/kth-largest-element-in-a-stream/
