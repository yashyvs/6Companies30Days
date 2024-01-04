class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int n, int delay, int forget, int start, vector<int> &dp) {
        if(dp[start] != -1) return dp[start];

        int ans = (start + forget) > n;

        for(int day=start+delay; day<min(start+forget, n+1); day++) {
            ans = (ans + solve(n, delay, forget, day, dp)) % mod;
        }
        return dp[start] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1, -1);
        return solve(n, delay, forget, 1, dp);
    }
};


/*
* Ques Link : https://leetcode.com/problems/number-of-people-aware-of-a-secret/
* Solution Link : https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/1136909674/
*/
