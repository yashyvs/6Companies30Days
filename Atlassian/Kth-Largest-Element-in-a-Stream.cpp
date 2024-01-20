class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num:nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};


/*
* Ques Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/
* Solution Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/1151857161/
*/
