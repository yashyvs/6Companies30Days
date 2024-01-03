class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> ans(n, vector<int> (m, -1));

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();


            for(int i=0; i<4; i++) {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==-1) {
                    ans[nrow][ncol]=ans[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/map-of-highest-peak/description/
* Solution Link : https://leetcode.com/problems/map-of-highest-peak/submissions/1135719667/
*/
