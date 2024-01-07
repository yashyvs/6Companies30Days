class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1, min(x2, xCenter));
        int y = max(y1, min(y2, yCenter));

        int distX = x - xCenter;
        int distY = y - yCenter;

        return (long long)distX*distX + (long long)distY*distY <= (long long)radius*radius;
    }
};


/*
* Ques Link : https://leetcode.com/problems/circle-and-rectangle-overlapping/
* Solution Link : https://leetcode.com/problems/circle-and-rectangle-overlapping/submissions/1139724811/
*/
