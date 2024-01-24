class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int collisions = 0;
        for(auto ch : directions) {
            if(ch == 'R') st.push(ch);
            else if(ch == 'L') {
                if(st.empty()) continue;
                if(st.top() == 'R') {
                    collisions += 2;
                    st.pop();
                    while(!st.empty()) {
                        if(st.top() == 'R') {
                            collisions++;
                        }
                        st.pop();
                    }
                }
                else {
                    collisions++;
                    st.pop();
                }
                st.push('S');
            }
            else {
                while(!st.empty()) {
                    if(st.top() == 'R') collisions++;
                    st.pop();
                }
                st.push('S');
            }
        }

        return collisions;
    }
};


/*
* Ques Link : https://leetcode.com/problems/count-collisions-on-a-road/
* Solution Link : https://leetcode.com/problems/count-collisions-on-a-road/submissions/1155804305/
*/
