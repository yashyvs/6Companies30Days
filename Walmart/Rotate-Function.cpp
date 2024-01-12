class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        int curr = 0;
        int n = nums.size();
        for( int i = 0; i<n; i++ ){
            curr += i * nums[i];
        }
        
        int ans = INT_MIN;
        ans = max(ans, curr);
        
        for(int i = 1; i<n; i++){
            int sum = total - nums[i-1];
            curr = curr - sum + (n-1) * nums[i-1];
            ans = max(ans, curr);
        }
        
        return ans;
        
    }
};


/*
* Ques Link : https://leetcode.com/problems/rotate-function/
* Solution Link : https://leetcode.com/problems/rotate-function/submissions/1144352382/
*/
