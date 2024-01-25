class Solution {
public:
    int mod = 1000000007;
    
    int solve(vector<int>& nums, int prev, int i, int mask, vector<vector<int>>& dp) { 
        if(i == nums.size()) return 1;
        if(dp[prev + 1][mask] != -1) return dp[prev + 1][mask];
        
        int ans = 0;
        for(int j=0; j<nums.size(); j++) {
            if ((mask & (1 << j)) > 0) continue;
            else {
                if (prev == -1 || nums[j] % nums[prev] == 0 || nums[prev] % nums[j] == 0) {
                    ans = (ans + solve(nums, j, i + 1, mask | (1 << j), dp)) % mod;
                }
            }
        }
        return dp[prev + 1][mask] = ans % mod;
    }

    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> ((1<<14)+1, -1));
        return solve(nums, -1, 0, 0, dp)%mod;
    }
};


/*
* Ques Link : https://leetcode.com/problems/special-permutations/
* Solution Link : https://leetcode.com/problems/special-permutations/submissions/1156698296/
*/
