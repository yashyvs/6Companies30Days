class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;
        vector<vector<long long>> mat(n, vector<long long> (n, 1e9));
        for(int i=0; i<original.size(); i++) {
            mat[original[i] - 'a'][changed[i] - 'a'] = min(mat[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }

        for(int i=0; i<n; i++) mat[i][i] = 0;

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        long long res = 0;
        for(int i=0; i<source.size(); i++) {
            if(mat[source[i] - 'a'][target[i] - 'a'] == 1e9) return -1;
            else res +=  mat[source[i] - 'a'][target[i] - 'a'];
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/minimum-cost-to-convert-string-i/
* Solution Link : https://leetcode.com/problems/minimum-cost-to-convert-string-i/submissions/1161923070/
*/
