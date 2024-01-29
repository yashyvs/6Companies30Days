class Solution {
public:
    string numberToWords(int num) {
        vector<pair<int, string>> mapping = {
            {1000000000, "Billion"},
            {1000000, "Million"},
            {1000, "Thousand"},
            {100, "Hundred"},
            {90, "Ninety"},
            {80, "Eighty"},
            {70, "Seventy"},
            {60, "Sixty"},
            {50, "Fifty"},
            {40, "Forty"},
            {30, "Thirty"},
            {20, "Twenty"},
            {19, "Nineteen"},
            {18, "Eighteen"},
            {17, "Seventeen"},
            {16, "Sixteen"},
            {15, "Fifteen"},
            {14, "Fourteen"},
            {13, "Thirteen"},
            {12, "Twelve"},
            {11, "Eleven"},
            {10, "Ten"},
            {9, "Nine"},
            {8, "Eight"},
            {7, "Seven"},
            {6, "Six"},
            {5, "Five"},
            {4, "Four"},
            {3, "Three"},
            {2, "Two"},
            {1, "One"}
        };

        if(num == 0) return "Zero";

        for(auto [number, word] : mapping) {
            if(num >= number) {
                string a = "";
                if(num >= 100) {
                    a = numberToWords(num / number) + " ";
                }
                string b = word;
                string c = "";
                if(num % number != 0) {
                    c = " " + numberToWords(num % number);
                }
                return a+b+c;
            }
        }
        return "";
    }
};


/*
* Ques Link : https://leetcode.com/problems/integer-to-english-words/
* Solution Link : https://leetcode.com/problems/integer-to-english-words/submissions/1160326593/
*/
