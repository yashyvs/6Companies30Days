class Solution {
public:
    bool solve(string& s, unordered_map<string, int>& mpp, int ind, vector<int>& dp) {
        if(ind >= s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];

        string curr = "";
        for(int i=ind; i<s.size(); i++) {
            curr.push_back(s[i]);
            if(mpp.contains(curr)) {
                if(solve(s, mpp, i+1, dp)) return 1;
            }
        }
        return dp[ind] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mpp;
        for(auto it:wordDict) {
            mpp[it]++;
        }

        vector<int> dp(s.size(), -1);
        return solve(s, mpp, 0, dp);
    }
};


/*
* Ques Link : https://leetcode.com/problems/word-break/
* Solution Link : https://leetcode.com/problems/word-break/submissions/1145095432/
*/
