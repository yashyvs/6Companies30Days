/*
Question link : https://leetcode.com/problems/airplane-seat-assignment-probability/
Submission link : https://leetcode.com/problems/airplane-seat-assignment-probability/submissions/870390957/
*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return (double)1;
        return (double)1/2;
    }
};
