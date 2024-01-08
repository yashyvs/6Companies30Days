class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.length();
        unordered_map<char, int> mpp1, mpp2;
        
        int bulls = 0;
        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            }
            else {
                mpp1[secret[i]]++;
                mpp2[guess[i]]++;
            }
        }

        int cows = 0;
        for(auto it:mpp1) {
            char ch = it.first;
            if(mpp2.contains(ch)) {
                cows += min(mpp1[ch], mpp2[ch]);
            }
        }

        string ans = "";
        ans += to_string(bulls);
        ans.push_back('A');
        ans += to_string(cows);
        ans.push_back('B');

        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/bulls-and-cows/
* Solution Link : https://leetcode.com/problems/bulls-and-cows/submissions/1140411514/
*/
