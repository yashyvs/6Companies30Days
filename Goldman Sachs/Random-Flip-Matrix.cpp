class Solution {
public:
    int m, n;
    set<pair<int, int>> st;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }
    
    vector<int> flip() {
        int row = rand() % m;
        int col = rand() % n;

        while(st.count({row, col}) > 0) {
            row = rand() % m;
            col = rand() % n;
        }
        st.insert({row, col});
        return {row, col};
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
