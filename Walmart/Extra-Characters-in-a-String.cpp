class Solution {
public:
    int solve(string& s, unordered_map<string, int>& mpp, int ind, vector<int>& dp) {
        if(ind >= s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        string curr = "";
        int ans = s.size();
        for(int i=ind; i<s.size(); i++) {
            curr.push_back(s[i]);
            
            int co = ((mpp.count(curr)) ? 0 : curr.size()) + solve(s, mpp, i+1, dp);
            ans = min(ans, co);
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mpp;
        for(auto& word:dictionary) {
            mpp[word]++;
        }
        vector<int> dp(s.size(), -1);
        return solve(s, mpp, 0, dp);
    }
};


/*
* Ques Link : https://leetcode.com/problems/extra-characters-in-a-string/
* Solution Link : https://leetcode.com/problems/extra-characters-in-a-string/submissions/1145083486/
*/
