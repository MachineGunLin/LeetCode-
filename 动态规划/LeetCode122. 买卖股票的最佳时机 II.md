# LeetCode122. 买卖股票的最佳时机 II

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200808150000233-2048442004.png)

题目说了可以无限次交易。又因为，对于一次从第i天买入，第j天卖出的交易方案，获得的利润等于prices[j] - prices[i]，即只和这次交易的买入和卖出当天的价格有关。
所以对于一个跨越连续多天的交易可以分割为连续多个的跨越一天的交易。

所以我们只需要选择那些能够获利的“两天”进行交易（前一天买入、后一天卖出），在每个能够获利的两天里，我们都能获取到这两天的差价作为利润。

只需要遍历一遍数组：寻找所有能够获得利润的两天，并对所有差价进行相加即可。

代码如下：

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int res = 0;
        for(int i = 0; i < size - 1; ++i) {
            if(prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};
```

股票系列问题还有一个比较通用的状态机dp解法，可以参考[买卖股票的最佳时机 IV](https://www.cnblogs.com/linrj/p/13456892.html).

可以用dp[i][k][0 or 1]表示当前天数为i，当前允许进行的最大交易次数k，已经当前时候持有股票（0表示不持有，1表示持有）可获得的最大利润。
由于这题可交易次数k为无穷大，也就是没有交易次数k的限制，因此我们只需要二维数组dp[i][0 or 1]表示第i天，持有或不持有股票能获得的最大利润。

对于dp[i][0],也就是一个不持有股票的状态，它由两种状态转移而来，也就是前一天就不持有股票: dp[i][0] = dp[i - 1][0];
还有前一天持有股票，在第i天把股票卖掉了：dp[i][0] = dp[i - 1][1] + prices[i];(加prices[i]表示卖掉股票获得的收益）
由于dp数组代表的是当前状态能获得的最大收益，因此需要对这两种状态取一个max: **dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);**

对于dp[i][1],也就是一个持有股票的状态，它也有两种状态转移而来，也就是前一天持有股票：dp[i][1] = dp[i - 1][1];
还有前一天不持有股票，在第i天买了一支股票：dp[i][1] = dp[i - 1][1] - prices[i];（减prices[i]表示买股票花了prices[i]的成本）
由于dp数组代表的是当前状态能获得的最大收益，所以也需要对这两种状态取一个max：**dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);**

由于状态转移方程对于dp[i][0 or 1]需要用到dp[i - 1][0 or 1]的值，所以我们需要处理边界dp[0][0 or 1]。

显然dp[0][0]为0，因为第0天，没买入股票就没有钱。
dp[0][1]为-prices[0]，表示第0天，花了prices[0]的钱买了一只股票。

最终返回的结果就是dp[n - 1][0](其中n是prices数组大小），表示最后一天，不持有股票的最大收益。
为什么不是dp[n - 1][1]？因为股票只有卖了才能赚钱，而且买股票还需要花钱，所以显然dp[n - 1][0]大于dp[n - 1][1]。

有了递推边界和状态转移方程，代码如下：

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for(int i = 0; i < n; ++i) {
            if(i == 0) {                              //处理一下递推边界
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
```