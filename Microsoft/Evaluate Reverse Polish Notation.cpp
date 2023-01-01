/*
Question link : https://leetcode.com/problems/evaluate-reverse-polish-notation/
Submission link : https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/869025936/
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto i : tokens) {
            if(i == "+" || i == "*" || i == "-" || i == "/") {
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();

                if(i == "+") st.push(b+a);
                if(i == "*") st.push(b*a);
                if(i == "-") st.push(b-a);
                if(i == "/") st.push(b/a);
            }
            else{
                int x = stoi(i);
                st.push(x);
            }
        }
        return st.top();
    }
};
