class Solution {
public:
    int longestString(int x, int y, int z) {
        int co = 0;
        while(x > 0 && y > 0) {
            co += 2;
            co += 2;
            x--;
            y--;   
        }
        if(x >= 1) co += 2;
        if(y >= 1) co += 2;
        co += (z*2);
        return co;
    }
};


/*
* Ques Link : https://leetcode.com/problems/construct-the-longest-new-string/
* Solution Link : https://leetcode.com/problems/construct-the-longest-new-string/submissions/1155809485/
*/
