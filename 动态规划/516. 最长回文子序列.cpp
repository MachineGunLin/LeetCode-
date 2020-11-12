/*
经典动态规划问题。用dp[i][j]表示字符串s的以i开头，以j结尾的子串的最大回文子序列的长度。我们要求的s的最长回文子序列的长度就是dp[0][n - 1]。

考虑一下数组的初始化，对于所有的i(0 <= i < n)，都有dp[i][i] = 1，表示单个字母可以组成一个长度为1的回文子序列。

然后要进行递推和状态转移，我们枚举子串的长度len从2到n，子串的起点i从0到n - len + 1。
n - len + 1是为了让当前子串的结尾不超过s的长度。
这样我们得到当前子串的起点i，和终点j = n - len + 1。

比较s[i]与s[j]是否相等。
（1）如果相等，说明子串s[i ~ j]可以在原来的子串s[i + 1 ~ j - 1]的基础上构成
一个长度+2的回文子序列。因此我们得到状态转移方程：dp[i][j] = dp[i + 1][j - 1] + 2
（2）如果不相等，说明子串s[i ~ j]无法在原来的子串s[i + 1 ~ j - 1]的基础上构成
一个长度+2的回文子序列，但是s[i + 1 ~ j]和s[i ~ j - 1]仍然有可能是一个回文子序列，我们要求的s[i ~ j]的最大回文子序列肯定是
s[i + 1 ~ j]和s[i ~ j - 1]两者中的最大回文子序列的较大者。因此我们得到状态转移方程：dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

枚举完长度和子串起点之后，最后返回的dp[0][n - 1]就是答案。
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
