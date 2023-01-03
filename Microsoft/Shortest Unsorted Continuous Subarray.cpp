/*
Question link : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
Submission link : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/870383123/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int st = 0;
        int en = n-1;
       
        for(int i = 0;i<n;i++) {
            if(nums[i] != sorted[i]) {
                st = i;
                break;
            }
            st++;
        }
        for(int i = n-1;i>=0;i--) {
            if(nums[i] != sorted[i]) {
                en = i;
                break;
            }
            en--;
        }
        if(st >= en) return 0;
        return en - st + 1;
    }
};
