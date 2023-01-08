/*
Question link : https://leetcode.com/problems/max-points-on-a-line/
Submission link : https://leetcode.com/problems/max-points-on-a-line/submissions/874206415/
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<double,int> mp[n];

        int ans = 1;
        for( int i = 0; i<n; i++ ){
            double x1 = points[i][0];
            double y1 = points[i][1];
            for(int j = 0; j<i; j++){
                double x2 = points[j][0];
                double y2 = points[j][1];
                double m = INT_MAX;
                
                if(x2-x1) m = (y2 - y1)/(x2 - x1);

                mp[i][m]++;
                ans = max(ans, mp[i][m]+1);
            }
        }

        return ans;
    }
};
