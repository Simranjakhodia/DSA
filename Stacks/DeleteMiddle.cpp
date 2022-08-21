//  https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1


class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void helper(stack<int>& s, int k) {
        if(s.empty())
            return;
        if(k == 1) {
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        helper(s, k-1);
        s.push(temp);
    }
    
    void deleteMid(stack<int>&s, int n)
    {
         int k = n/2 + 1;
         helper(s, k);
    }
};
