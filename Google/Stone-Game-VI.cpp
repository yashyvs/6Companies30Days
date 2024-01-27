class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> v;

        int n = aliceValues.size();

        for(int i=0; i<n; i++) {
            v.push_back({aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]});
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int a = 0, b = 0;
        for(int i=0; i<n; i++) {
            if(i%2 == 0) a += v[i][1];
            else b += v[i][2];
        }

        if(a == b) return 0;
        else if(a > b) return 1;
        else return -1;
    }
};


/*
* Ques Link : https://leetcode.com/problems/stone-game-vi/
* Solution Link : https://leetcode.com/problems/stone-game-vi/submissions/1158457508/
*/
