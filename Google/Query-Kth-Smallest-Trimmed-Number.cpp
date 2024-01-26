class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto query:queries) {
            int k=query[0];
            int len = query[1];

            priority_queue<pair<string, int>> pq;
            
            for(int i=0; i<nums.size(); i++) {
                string num = nums[i];
                string trimmed = num.substr(num.size() - len);
                
                pq.push({trimmed, i});
            }
            while(pq.size() > k) {
                pq.pop();
            }

            int ind = pq.top().second;
            ans.push_back(ind);            
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/query-kth-smallest-trimmed-number/
* Solution Link : https://leetcode.com/problems/query-kth-smallest-trimmed-number/submissions/1157552489/
*/
