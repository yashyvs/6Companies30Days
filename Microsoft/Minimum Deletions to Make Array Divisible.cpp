/*
Question link : https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
Submission link : https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/871230925/
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums) pq.push(i);
        int gcd = 0;
        for(int i  = 0;i<numsDivide.size();i++) {
            gcd = __gcd(gcd,numsDivide[i]);
        }

        int ans = 0;
        while(!pq.empty()) {
            int x = pq.top();
            if(gcd%x == 0) break;
            else {
                ans++;
                pq.pop();
            }
        }
        if(ans == nums.size()) return -1;
        return ans;
        
    }
};
