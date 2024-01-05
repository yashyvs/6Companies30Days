class Solution {
public:
    long long gcd(long long int a, long long int b) { 
        if (b == 0) return a; 
        return gcd(b, a % b); 
    } 
    long long lcm(int a, int b) { 
        return (a / gcd(a, b)) * b; 
    }
    bool isPossible(long long x, int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long bothCanDivide = x / lcm(divisor1, divisor2);
        long long div1CanDivide = x / divisor1 - bothCanDivide;
        long long div2CanDivide = x / divisor2 - bothCanDivide;

        long long bothCannotDivide = x - bothCanDivide - div1CanDivide - div2CanDivide;

        if(div2CanDivide < uniqueCnt1) bothCannotDivide-=(uniqueCnt1 - div2CanDivide);
        if(div1CanDivide < uniqueCnt2) bothCannotDivide-=(uniqueCnt2 - div1CanDivide);

        return bothCannotDivide >= 0;        
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l=1;
        long long r=INT_MAX;

        while(l <= r) {
            long long mid = l + (r-l)/2;
            if(isPossible(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};


/*
* Ques Link : https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
* Solution Link : https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/submissions/1137761758/
*/
