class Solution {
public:
    const int MOD = 1000000007;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto num : nums) {
            pq.push(num);
        }

        while(k) {
            int num = pq.top();
            pq.pop();
            num++;
            pq.push(num);
            k--;
        }

        long long res = 1;
        while(!pq.empty()) {
            int num = pq.top();
            pq.pop();
            res = (res*num) % MOD;
        }
        return res % MOD;
    }
};


/*
* Ques Link : https://leetcode.com/problems/maximum-product-after-k-increments/
* Solution Link : https://leetcode.com/problems/maximum-product-after-k-increments/submissions/1159426432/
*/
