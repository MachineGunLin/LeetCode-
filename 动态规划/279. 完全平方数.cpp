/*
用dp[i]表示组成i的最少的完全平方数的个数。
如果有一个j, 1<=j且j*j <= i，如果j的平方是组成i的完全平方数的其中之一个完全平方数，则可以考虑用dp[i - j * j]来更新dp[i]。
即dp[i] = min(dp[i], dp[i - j * j] + 1); 表示组成i的最少的完全平方数的方案是组成i-j*j的最少的完全平方数的方案加上j的平方。
i从小到大从1到n递推，不断更新dp[i]的值，最后返回dp[n]就是答案。
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
