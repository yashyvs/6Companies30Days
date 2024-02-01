class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = hBars.size();
        int v = vBars.size();
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxH = 1;
        int curr = 1;
        for(int i=1; i<hBars.size(); i++) {
            if(hBars[i] == hBars[i-1] + 1) {
                curr++;
            }
            else curr = 1;
            maxH = max(maxH, curr);
        }

        int maxV = 1;
        curr = 1;
        for(int i=1; i<vBars.size(); i++) {
            if(vBars[i] == vBars[i-1] + 1) {
                curr++;
            }
            else curr = 1;
            maxV = max(maxV, curr);
        }

        int side = min(maxH+1, maxV+1);
        return side*side;
    }
};


/*
* Ques Link : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
* Solution Link : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/submissions/1163065455/
*/
