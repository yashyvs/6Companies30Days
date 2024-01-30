class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        priority_queue<pair<int, int>> pq;
        
        int res = nums[0];
        dp[0] = nums[0];
        
        pq.push({dp[0], 0});
        
        for(int i=1; i<nums.size(); i++) {
            auto t = pq.top();
            while(t.second < i - k) {
                pq.pop();
                t = pq.top();
            }
            dp[i] = max(0, t.first) + nums[i];
            res = max(res, dp[i]);
            pq.push({dp[i], i});
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/constrained-subsequence-sum/
* Solution Link : https://leetcode.com/problems/constrained-subsequence-sum/submissions/1161301882/
*/
