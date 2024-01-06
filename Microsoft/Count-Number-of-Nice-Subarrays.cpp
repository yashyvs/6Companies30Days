class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]&1) {
                nums[i] = 1;
            }
            else {
                nums[i] = 0;
            }
        }

        unordered_map<int, int> mpp;
        int sum = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];

            if(sum == k) cnt++;

            if(mpp.contains(sum - k)) {
                cnt += mpp[sum-k];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};


/*
* Ques Link : https://leetcode.com/problems/count-number-of-nice-subarrays/
* Solution Link : https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/1138754423/
*/
