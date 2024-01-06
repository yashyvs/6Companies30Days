class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> res = img;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int curr = 0, co = 0;
                for(int row = -1; row<=1; row++) {
                    for(int col = -1; col<=1; col++) {
                        int nrow = i+row;
                        int ncol = j+col;

                        if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m) {
                            curr += img[nrow][ncol];
                            co++;
                        }
                    }
                }
                res[i][j] = curr/co;
            }
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/image-smoother/
* Solution Link : https://leetcode.com/problems/image-smoother/submissions/1138263933/
*/
