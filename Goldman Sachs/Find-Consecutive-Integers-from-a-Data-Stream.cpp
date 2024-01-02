class DataStream {
private:
    int val, size;
    int cnt = 0;
public:
    DataStream(int value, int k) {
        val = value;
        size = k;
    }
    
    bool consec(int num) {
        if(val == num) cnt++;
        else cnt = 0;

        if(cnt >= size) return true;
        else return false;
    }
};

/*
* Ques Link : https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
* Solution Link : https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/submissions/1134647484/
*/
