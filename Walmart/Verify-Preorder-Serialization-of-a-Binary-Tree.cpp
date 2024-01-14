class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy = 1;
        for(int i=0; i<preorder.length(); i++) {
            if(preorder[i] == ',') continue;
            if(i!=0 && preorder[i] >= '0' && preorder[i-1] >= '0') continue;
            
            vacancy--;
            if(vacancy < 0) return false;
            
            if(preorder[i] >= '0') vacancy+=2;
        }
        return vacancy == 0;
    }
};


/*
* Ques Link : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
* Solution Link : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/submissions/1146164096/
*/
