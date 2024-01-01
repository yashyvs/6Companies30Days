class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mpp;
        for(int i=0; i<access_times.size(); i++) {
            int time = stoi(access_times[i][1]);
            mpp[access_times[i][0]].push_back(time);
        }

        vector<string> ans;
        for(auto it:mpp) {
            sort(it.second.begin(), it.second.end());

            for(int i=2; i<it.second.size(); i++) {
                if(it.second[i] - it.second[i-2] < 100) {
                    ans.push_back(it.first);
                    break;
                }
            }   
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/high-access-employees/
* Solution Link : https://leetcode.com/problems/high-access-employees/submissions/1133884465/
*/
