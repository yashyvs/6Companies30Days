class Solution {
private:
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
    }
    
    vector<int> pick() {
        int sum = 0;
        vector<int> ans;
        
        for (auto it : rects) {
            int area = (it[2] - it[0] + 1) * (it[3] - it[1] + 1);
            sum += area;
            
            if (rand() % sum < area) ans = it;
        }
        
        int x = rand() % (ans[2] - ans[0] + 1) + ans[0];
        int y = rand() % (ans[3] - ans[1] + 1) + ans[1];
        
        return { x, y };
    }
};

/*
* Ques Link : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
* Solution Link : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/1141504107/
*/
