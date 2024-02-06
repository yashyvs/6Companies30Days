class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0 && grid[newRow][newCol] && !vis[newRow][newCol]) {
                dfs(newRow, newCol, grid, vis);
            }
        }
    }

    int numberOfIsland(vector<vector<int>> &grid) {
        int land = 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    land++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return land;
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        if(numberOfIsland(grid) > 1) return 0;

        int one = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    one++;
                    grid[i][j] = 0;
                    if(numberOfIsland(grid) > 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        if(one == 0) return 0;
        else if(one == 1) return 1;
        else return 2;
    }
};


/*
* Ques Link : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
* Solution Link : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/submissions/1167835841/
*/
