class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;

        int i=0, j=0;
        int res=0;
        while(j < n) {
            mpp[nums[j++]]++;
            while(mpp[nums[j-1]] > k) {
                mpp[nums[i++]]--;
            }
            res = max(res, j-i);
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
* Solution Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/submissions/1152736072/
*/
