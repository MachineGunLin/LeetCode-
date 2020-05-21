class Solution {
/*
方法一：暴力（超时）
*/

public:
    bool checkPalindrome(string s, int start, int end) {
        if(s.size() < 2) {
            return true;
        }
        int size = end - start + 1;
        for(int i = 0; i < size / 2; ++i) {
            if(s[start + i] != s[end - i]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size() < 2) {
            return s;
        }
        string res;
        for(int i = 0; i < s.size() - 1; ++i) {
            for(int j = s.size() - 1; j >=i; --j) {
                if(checkPalindrome(s, i, j) == true) {
                    res = res.size() > j - i + 1 ? res : s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};


/*
方法二：动态规划
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length));
        string res;
        for(int len = 0; len < length; ++len) {
            for(int i = 0; i < length - len; ++i) {
                int j = i + len;
                if(len == 0) {
                    dp[i][j] = 1;
                } else if(len == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if(dp[i][j] && len >= res.size()) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};
