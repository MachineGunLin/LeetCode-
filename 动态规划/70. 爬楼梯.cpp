/*
用 dp[i] 表示爬到第 i 层的不同的方法数。
要爬到第i层有两种方式，第一种是从第 i - 1层 再爬一层，
第二种是从第 i - 2层 再爬两层，两种方式都可以只用再爬 一次 就到第 i 层。
所以爬到第 i 层的方法数 dp[i] 是爬到第 i - 1层的方法数 dp[i - 1] 加上
第 i - 2 层的方法数dp[i - 2]，
所以我们得到状态转移方程 dp[i] = dp[i - 1] + dp[i - 2]。
最终返回结果第 n 层的方法数就是 dp[n]。
由于状态转移方程类似递归，所以需要有递归边界，
显然第0层的方法数和第1层的方法数都是1，所以初始化 dp[0] = dp[1] = 1
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
