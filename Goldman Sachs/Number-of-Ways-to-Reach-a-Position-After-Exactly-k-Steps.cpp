class Solution {
public:
const int MOD = 1e9 + 7;
    int solve(int currPos, int endPos, int k, vector<vector<int>> &dp) {
        if(k == 0) {
            if(currPos == endPos) return 1;
            else return 0;
        }
        if(dp[currPos+1000][k] != -1) return dp[currPos+1000][k];

        int left = solve(currPos-1, endPos, k-1, dp);
        int right = solve(currPos+1, endPos, k-1, dp);

        return dp[currPos+1000][k] = (left + right) % MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int> (k+1, -1));
        return solve(startPos, endPos, k, dp);
    }
};


/*
* Ques Link : https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
* Solution Link : https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/submissions/1134603083/
*/
