class Solution {
public:
    bool check(vector<int> vec) {
        for(int i=1; i<vec.size(); i++) {
            if(vec[i] <= vec[i-1]) return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {

                vector<int> vec;
                for(int k=0; k<i; k++) {
                    vec.push_back(nums[k]);
                }

                for(int k=j+1; k<n; k++) {
                    vec.push_back(nums[k]);
                }

                if(check(vec)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/
* Solution Link : https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/submissions/1140640450/
*/
