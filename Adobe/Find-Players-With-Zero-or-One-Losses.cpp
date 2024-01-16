class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> player(100001, 0);
        
        for(auto match:matches) {
            int winner = match[0];
            int looser = match[1];

            if(player[winner] == 0 || player[winner] == 1) {
                player[winner] = 1;
            }
            if(player[looser] >= 0) player[looser] = -1;
            else if(player[looser] == -1) player[looser]--;
        }

        vector<vector<int>> res;
        vector<int> allWin, oneLoss;
        
        for(int i=1; i<player.size(); i++) {
            if(player[i] == 1) {
                allWin.push_back(i);
            }
            if(player[i] == -1) {
                oneLoss.push_back(i);
            }
        }

        res.push_back(allWin);
        res.push_back(oneLoss);

        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
* Solution Link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/submissions/1148016062/
*/
