class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
       int ans = 0;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == 'X') {
                    if((i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X')) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/battleships-in-a-board/
* Solution Link : https://leetcode.com/problems/battleships-in-a-board/submissions/1144393170/
*/
