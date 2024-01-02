string encode(string src) {

    string res = "";
    int cnt = 0;
    for (int i = 0; i < src.length(); i++) {
        if (i == 0 || src[i] != src[i - 1]) {
            if (i != 0) {
                res += to_string(cnt);
            }
            res.push_back(src[i]);
            cnt = 1;
        }
        else if (src[i] == src[i - 1]) {
            cnt++;
        }
    }
    res += to_string(cnt);
    return res;
}


/*
* Ques Link : https://www.geeksforgeeks.org/problems/run-length-encoding/1
*/
