class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {
            return true;
        }
        string s3 = s1, s4 = s2;
        sort(s3.begin(), s3.end());
        sort(s4.begin(), s4.end());
        if(s3 != s4) {
            return false;
        }
        int n = s1.size();
        for(int i = 1; i <= n - 1; ++i) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            } 
            if(isScramble(s1.substr(0, n - i), s2.substr(i)) && isScramble(s1.substr(n - i), s2.substr(0, i))) {
                return true;
            }
        }
        return false;
    }
};
