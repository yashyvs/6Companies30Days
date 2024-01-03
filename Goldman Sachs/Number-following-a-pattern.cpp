class Solution{   
public:
    void rev(string &S, int i, int j) {
        while(i < j) {
            swap(S[i], S[j]);
            i++;
            j--;
        }
    }
    string printMinNumberForPattern(string S){
        int n=S.length();
        string res="";
        for(int i=1; i<=n+1; i++) {
            res+=to_string(i);
        }
        int i=0;
        while(i < n) {
            int j=i;
            while(S[j] == 'D') j++;
            if(i < j) {
                rev(res, i, j);
            }
            i=j+1;
        }
        return res;
    }
};


/*
* Ques Link : https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
*/
