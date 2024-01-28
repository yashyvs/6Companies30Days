class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for(int i=0; i<asteroids.size(); i++) {
            if(m >= asteroids[i]) {
                m += asteroids[i];
            }
            else return false;
        }
        return true;
    }
};


/*
* Ques Link : https://leetcode.com/problems/destroying-asteroids/
* Solution Link : https://leetcode.com/problems/destroying-asteroids/submissions/1159410164/
*/
