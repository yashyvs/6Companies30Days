long long mod = 1e9+7;
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        
        unordered_map<int, int>m;
        int ones = 0, res=0;
        
        int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        vector<int> dp(1<<10, 0), tmp;
        dp[0] = 1;
        
        for(auto x:nums){
            if(x%4==0 || x%9==0 || x%25==0) continue;
            if(x==1) ones++;
            else m[x]++;
        }
        
        for(auto x:m){
            int curr_mask = 0;
            for(int i=0; i<10; i++)
                if(x.first%prime[i]==0) 
                    curr_mask+=(1<<i);
            
            tmp.assign(1<<10, 0);
            for(int mask=0; mask<(1<<10); mask++)
                if( (curr_mask & mask) ==0)
                    tmp[mask | curr_mask] = ((long long) dp[mask]*(long long) x.second)%mod;  //x.second is frequency
            
            for(int i=0; i<(1<<10); i++)
                dp[i] = (dp[i]+tmp[i] )%mod;
            
        }
        
        for(int i=1; i<(1<<10); i++) res =(res+dp[i] )%mod;
        
        while(ones--){
            res = ( (long long)res*2LL)%mod;
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/the-number-of-good-subsets/
* Solution Link : https://leetcode.com/problems/the-number-of-good-subsets/submissions/1169989013/
*/
