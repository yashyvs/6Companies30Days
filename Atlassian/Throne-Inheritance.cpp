class ThroneInheritance {
public:
    unordered_map<string, pair<bool, vector<string>>> mp;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].second.push_back(childName);
    }
    
    void death(string name) {
        mp[name].first = true;
    }
    
    void dfs(string parentName, vector<string>& res) {
        if(!mp[parentName].first) {
            res.push_back(parentName);
        }

        for(auto child : mp[parentName].second) {
            dfs(child, res);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(king, res);
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/throne-inheritance/
* Solution Link : https://leetcode.com/problems/throne-inheritance/submissions/1152760607/
*/
