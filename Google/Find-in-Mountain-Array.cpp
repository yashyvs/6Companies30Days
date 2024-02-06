class Solution {
public:
    int peakEl(MountainArray &mountainArr, int lo, int hi) {
        int index = -1;

        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                lo = mid+1;
                index = mid+1;
            }
            else {
                hi = mid;
            }
        }
        return index;
    }

    int bsI(MountainArray &mountainArr, int lo, int hi, int target) {
        if(lo > hi) return -1;

        int mid = lo + (hi - lo)/2;

        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) >  target) return bsI(mountainArr, lo, mid-1, target);
        else return bsI(mountainArr, mid+1, hi, target);
    }

    int bsD(MountainArray &mountainArr, int lo, int hi, int target) {
        if(lo > hi) return -1;

        int mid = lo + (hi - lo)/2;

        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) <  target) return bsD(mountainArr, lo, mid-1, target);
        else return bsD(mountainArr, mid+1, hi, target);
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int index = peakEl(mountainArr, 0, n-1);

        int l = bsI(mountainArr, 0, index, target);
        if(l != -1) return l;
        int r = bsD(mountainArr, index, n-1, target);
        return r;
    }
};


/*
* Ques Link : https://leetcode.com/problems/find-in-mountain-array/
* Solution Link : https://leetcode.com/problems/find-in-mountain-array/submissions/1168010501/
*/
