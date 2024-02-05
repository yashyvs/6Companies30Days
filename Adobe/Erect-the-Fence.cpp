class Solution {
public:
    int calculate(vector<int> &p1, vector<int> &p2, vector<int> &p3){
        int x1 = p1[0], x2 = p2[0], x3 = p3[0];
        int y1 = p1[1], y2 = p2[1], y3 = p3[1];

        return (y3 - y2)*(x2 - x1) - (y2 - y1)*(x3 - x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> upper, lower;
        for(auto i : trees){
            int l = lower.size();
            int u = upper.size();
            vector<int> point = {i[0], i[1]};

            while(u >= 2 && calculate(upper[u-2], upper[u-1], point) < 0){
                u--;
                upper.pop_back();
            }

            while(l >= 2 && calculate(lower[l-2], lower[l-1], point) > 0){
                l--;
                lower.pop_back();
            }
            upper.push_back(point);
            lower.push_back(point);
        }
        set<vector<int>> st;
        for(auto i : upper){
            st.insert(i);
        }
        for(auto i : lower){
            st.insert(i);
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/erect-the-fence/
* Solution Link : https://leetcode.com/problems/erect-the-fence/submissions/1167063846/
*/
