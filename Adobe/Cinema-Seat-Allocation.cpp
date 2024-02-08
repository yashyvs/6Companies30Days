class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int i=0;
        int count = 0, prev = 0;
        sort(reservedSeats.begin(),reservedSeats.end());
        vector<int> v;

        count += 2*(n-reservedSeats[reservedSeats.size()-1][0]);
        
        while(i<reservedSeats.size()) {
            v = vector<int>(10,1);
            int rownum = reservedSeats[i][0];
            if((prev+1) != rownum) count+=2*(rownum-prev-1);
            prev = rownum;
            while(i<reservedSeats.size() && reservedSeats[i][0]==rownum) {
                v[reservedSeats[i][1]-1] = 0;
                i++;
            }
            int c1 = v[1] & v[2] & v[3] & v[4] & v[5] & v[6] & v[7] & v[8];
            int c2 = (v[1] && v[2] && v[3] && v[4]) | (v[3] & v[4] & v[5] & v[6]) | (v[5] & v[6] & v[7] & v[8]);

            if(c1) count+=2;
            else if(c2) count+=1;
        }
        return count;
    }
};


/*
* Ques Link : https://leetcode.com/problems/cinema-seat-allocation/
* Solution Link : https://leetcode.com/problems/cinema-seat-allocation/submissions/1169836323/
*/
