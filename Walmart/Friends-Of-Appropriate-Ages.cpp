class Solution {
public:
    bool check(int x, int y) {
        return !((y <= 0.5*x + 7) || y > x || (y > 100 && x < 100));
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> mp;
        for (auto i:ages) mp[i]++;
        
        int res = 0;
        for(auto i : mp) {
            for(auto j : mp) {
                int x = i.first;
                int y = j.first;
                if(check(x, y)) {
                    int xCount = i.second;
                    int yCount = j.second;
                     
                    if(x!=y) res += xCount * yCount;
                    else res += xCount * (yCount-1);
                }
            }
        }
        return res;
    }
};


/*
*Ques Link : https://leetcode.com/problems/friends-of-appropriate-ages/
* Solution Link : https://leetcode.com/problems/friends-of-appropriate-ages/submissions/1147066561/
*/
