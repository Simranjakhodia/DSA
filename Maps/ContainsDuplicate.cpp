// https://leetcode.com/problems/contains-duplicate/


class Solution {
public:
    
bool containsDuplicate1(vector<int>& nums){  // 33ms faster 22.5mb less
   if(nums.empty()){return false;}
    unordered_map <int, int> m;
    for(auto i : nums){
        if(++m[i] > 1)
            return true;
    }
     return false;
}
    
bool containsDuplicate(vector<int> &nums){ //  67 ms faster 21mb less
    if(nums.empty()) return false;
    set<int> m;
    for(auto num : nums){
        if(m.find(num) != m.end())
            return true;
        m.insert(num);
    }
       return false; 
}
    
bool containsDuplicate3(vector<int> &nums){ //  69 ms faster 20.8mb less
    if(nums.empty()) return false;
    multimap<int, bool> m;
    for(auto num : nums ){
        if(m.find(num) != m.end())
            return true;
        m.insert(make_pair(num, true));
    }
    return false;
}
bool containsDuplicate4(vector<int>& nums) { //  20 ms faster 15.6mb less
    sort(nums.begin(), nums.end());
    for (int i=0; i<int(nums.size())-1; i++) {
        if (nums[i]==nums[i+1])
            return true;
    }
    return false;    
}    
    
};
