class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        int i=n-1;

        vector<int> vec(n);
        for(int j=1; j<n; j+=2) {
            vec[j] = nums[i--];
        }
        for(int j=0; j<n; j+=2) {
            vec[j] = nums[i--];
        }
        nums = vec;
    }
};


/*
* Ques Link : https://leetcode.com/problems/wiggle-sort-ii/
* Solution Link : https://leetcode.com/problems/wiggle-sort-ii/submissions/1142614488/
*/
