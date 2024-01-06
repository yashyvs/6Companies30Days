class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i=0, j=nums.size()-1;
        int cnt = 0;
        while(i < j) {
            cnt += (nums[j] - nums[i]);
            i++;
            j--;
        }

        return cnt;
    }
};


/*
* Ques Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
* Solution Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/1138759876/
*/
