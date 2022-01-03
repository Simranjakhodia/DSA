//  https://leetcode.com/problems/unique-binary-search-trees/submissions/

// Problem approach : nth catalan number

class Solution {
   
public:
    /*int numTrees(int n) {
        if(n == 0 || n == 1) return n;
        vector<int>dp (n+1, 0);
        for(auto i : dp) {
            dp[i] = 0;
        }
        dp[0] = 1 ; dp [1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
    
    // https://leetcode.com/problems/unique-binary-search-trees/discuss/1565533/Java-Simple-and-Clean-DP-solution-w-detailed-example-or-Beats-100-or-TC%3A-O(N2)-SC%3A-O(N)
    */ 
    int numTrees(int n){
        if(n ==0 || n==1) return n;
        int dp[20];
        memset(dp, 0, sizeof dp);
        dp[0] = 1 ; dp [1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
