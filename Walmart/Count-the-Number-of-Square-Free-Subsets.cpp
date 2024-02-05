class Solution {
private:
    const int MOD = 1000000007;
    const int primeFactors[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> squareFreeBitmaps;
        for (int num : nums) {
            if (isSquareFree(num)) {
                squareFreeBitmaps.push_back(convertToBitmap(num));
            }
        }

        vector<vector<int>> dp(squareFreeBitmaps.size() + 1, vector<int>(1 << 10, -1));

        return countSubsets(0, 0, dp, squareFreeBitmaps);
    }

    int countSubsets(int idx, int bitmask, vector<vector<int>>& dp, const vector<int>& squareFreeBitmaps) {
        if (idx >= squareFreeBitmaps.size()) {
            return 0;
        }

        if (dp[idx][bitmask] >= 0) {
            return dp[idx][bitmask];
        }

        int currentBitmap = squareFreeBitmaps[idx];
        int count = countSubsets(idx + 1, bitmask, dp, squareFreeBitmaps);

        if ((bitmask & currentBitmap) == 0) {
            count = (count + 1 + countSubsets(idx + 1, bitmask | currentBitmap, dp, squareFreeBitmaps)) % MOD;
        }

        dp[idx][bitmask] = count;
        return count;
    }
    int convertToBitmap(int num) {
        int bitmap = 0;
        for (int i = 0; i < 10; ++i) {
            if (num % primeFactors[i] == 0) {
                bitmap += 1 << i;
            }
        }
        return bitmap;
    }

    bool isSquareFree(int num) {
        for (int pf : primeFactors) {
            if (num % (pf * pf) == 0) {
                return false;
            }
        }
        return true;
    }
};


/*
* Ques Link : https://leetcode.com/problems/count-the-number-of-square-free-subsets/
* Solution Link : https://leetcode.com/problems/count-the-number-of-square-free-subsets/submissions/1166746685/
*/
