/*
Question link : https://leetcode.com/problems/bulls-and-cows/
Submission link : https://leetcode.com/problems/bulls-and-cows/submissions/869046082/
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        map<int,int> mp1,mp2;
        int bulls = 0;
        int cows = 0;
        for(int i = 0;i<n;i++) { 
            if(secret[i] == guess[i]) bulls++;
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }

        for(auto it:mp1)
        {
            if(mp2.find(it.first)!=mp2.end())
            cows+=min(mp2[it.first],it.second);
        }
        string ans = "";
        ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};
