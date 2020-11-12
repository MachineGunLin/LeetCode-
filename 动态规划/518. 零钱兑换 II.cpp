/*
用dp[i]表示当面值为i的时候，不同的方案个数。目标是求出凑出amount的方案个数，也就是dp[amount]。
对于每个coins[i]，可以得到当金额j为coins[i] ~ amount的方案数dp[j] += d[j - coins[i]，也就是金额j可以由金额j - coins[i]加一枚coins[i]硬币得到，
所以凑出j的所有方案里一定包含有凑出j - coins[i]的方案，在这个方案的基础上加上一枚coins[i]就得到金额j了。

因此我们只需要枚举所有的coins，对于每个coins[i]，求出由它可以拼凑出的所有金额方案coins[i]（最小金额）~ amount（最大金额）的方案数量：
dp[j] += dp[j - coins[i]]

再处理一下递推边界：dp[0] = 1。因为当一枚金币也不出的时候，实际上也是一种方案。

递推结束之后，返回dp[amount]，就是我们需要的答案。
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
