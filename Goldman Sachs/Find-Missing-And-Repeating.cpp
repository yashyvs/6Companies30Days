class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int x = 0;
        for(int i=0; i<n; i++) {
            x ^= arr[i];
            x ^= (i+1);
        }
        
        int bitNo = 0;
        while(true) {
            if((x & (1<<bitNo)) != 0) {
                break;
            }
            bitNo++;
        }
        
        int zero = 0, one = 0;
        
        for(int i=0; i<n; i++) {
            if((arr[i] & (1<<bitNo)) != 0) {
                one ^= arr[i];
            }
            else {
                zero ^= arr[i];
            }
        }
        
        for(int i=1; i<=n; i++) {
            if((i & (1<<bitNo)) != 0) {
                one ^= i;
            }
            else {
                zero ^= i;
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++) {
            if(arr[i] == zero) cnt++;
        }
        
        if(cnt == 2) return {zero, one};
        else return {one, zero};
    }
};


/*
* Ques Link : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
*/
