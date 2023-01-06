/*
Question link : https://leetcode.com/problems/factorial-trailing-zeroes/
Submission link : https://leetcode.com/problems/factorial-trailing-zeroes/submissions/872526527/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int co = 0;
        while(n>0){
            co += n/5;
            n/=5;
        }
        return co;
    }
};
