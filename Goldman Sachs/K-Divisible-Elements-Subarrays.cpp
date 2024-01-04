class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> st;
        for(int i=0; i<nums.size(); i++) {
            int cnt = 0;
            string str = "";
            for(int j=i; j<nums.size(); j++) {
                if(nums[j] % p == 0) cnt++;
                if(cnt > k) break;

                str += nums[j];
                str += "-";
                st.insert(str);
            }
        }
        return st.size();
    }
};


/*
* Ques Link : https://leetcode.com/problems/k-divisible-elements-subarrays/
* Solution Link : https://leetcode.com/problems/k-divisible-elements-subarrays/submissions/1136812679/
*/
