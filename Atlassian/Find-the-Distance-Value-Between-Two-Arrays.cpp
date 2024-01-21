class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int co = 0;
        for(int i=0; i<arr1.size(); i++) {
            bool flag = true;
            for(int j=0; j<arr2.size(); j++) {
                if(abs(arr1[i]-arr2[j]) <= d) {
                    flag = false;
                }
            }

            if(flag == true) {
                co++;
            }
        }
        return co;
    }
};


/*
* Ques Link : https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
* Solution Link : https://leetcode.com/problems/find-the-distance-value-between-two-arrays/submissions/1152722733/
*/
