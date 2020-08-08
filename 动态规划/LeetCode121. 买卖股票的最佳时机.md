# LeetCode121. 买卖股票的最佳时机

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200808121831779-1655390672.png)

由于只能交易一次，即买入卖出一次，所以我们考虑在某个价值较低的某天买入，在之后的某个价值较高的一天卖出，以获取最高的差价利润。

最简单的想法是枚举所有天数，然后枚举某天之后的所有天数，更新能够获取到的最高利润。
这样做需要两重循环，时间复杂度是O(n^2)，超时。

我们可以边枚举天数边记录当前的最低价格和能获取到的最高利润（最高利润就是当前的价格减去当前记录的最低价格）。
这样时间复杂度可以降到O(n)。

代码如下：

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int lowestPrice = INT_MAX;                  //记录截止到当前天数的最低价格
        for(auto price : prices) {
            lowestPrice = min(lowestPrice, price);            //更新最低价格
            res = max(res, price - lowestPrice);              //计算当前价格减去最低价格，更新利润（最高差价）
        }
        return res;
    }
};
```

这题还有一个通用的做法，可以参考[买卖股票的最佳时机 IV](https://www.cnblogs.com/linrj/p/13456892.html)。

用一个状态转移方程dp[i][k][0 or 1]表示当前天数第i天，最高交易次数（买入次数）为k，持有或不持有（1表示持有，0表示不持有股票时）的最高利润。

由于这道题k最大为1，所以k只能是0或1，当k为0时dp值肯定为0，因为不买入股票就没有利润，所以状态可以压缩到二维, dp[i][0 or 1]表示第i天，持有或持有股票时的最高利润。
具体分析可以看上面那个链接。

代码如下：
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2));
        for(int i = 0; i < n; ++i) {
            if(i == 0) {                        //边界情况要特殊处理
                dp[i][0] = 0;
                dp[i][1] = -prices[i];            //第0天花了prices[0]的成本买入股票
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);      //状态转移方程，不持有股票的状态由前一天也不持有股票和前一天持有股票，第i天卖掉两种状态转移而来
            dp[i][1] = max(dp[i - 1][1], -prices[i]);              //状态转移方程，持有股票的状态由前一天就持有股票和前一天不持有股票，第i天买入股票两种状态转移而来。 由于交易次数最大为1，所以前一天不持有股票，dp[i - 1][0]肯定是0，所以第二个参数是-prices[i]
        }
        return dp[n - 1][0];            //最后答案就是最后一天，不持有股票的最高利润。是dp[n - 1][0]不是dp[n - 1][1]，是因为不持有股票（卖出股票）肯定比持有股票的利润高，因为买股票要钱（成本），持有股票本身没法赚钱，卖了才有利润
    }
};
```