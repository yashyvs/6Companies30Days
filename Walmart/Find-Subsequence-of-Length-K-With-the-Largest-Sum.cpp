class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        
        int n=nums.size();
        for(int i=0; i<n; i++) {
            pq.push({nums[i], i});
        }
        
        vector<pair<int, int>> vec;
        while(pq.size() > n-k) {
            int el = pq.top().first;
            int index = pq.top().second;
            vec.push_back({index, el});
            pq.pop();
        }
        sort(vec.begin(), vec.end());

        vector<int> res;
        for(auto [index, el] : vec) {
            res.push_back(el);
        } 
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
* Solution Link : https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/submissions/1143274115/
*/
