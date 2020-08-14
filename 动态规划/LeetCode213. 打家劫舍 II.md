# LeetCode213. 打家劫舍 II

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200814202502053-107188407.png)

这题是[LeetCode198. 打家劫舍](https://www.cnblogs.com/linrj/p/13433860.html)的进阶版，除了要求不能
打劫相邻的房子以外，还不能同时打劫第一个和最后一个房子。因为所有房子的排列是环形的，所以实际上第一个房子和
最后一个房子也是相邻的。

我们也用dp[i]表示打劫到第i个房子能获得的最大收益，要打劫到最后一个房子，就得不打劫第一个房子，所以我们需要考虑两种
情况，打劫第一个房子和不打劫第一个房子。

如果我们打劫了第一个房子，那么就不能考虑最后一个房子了，可打劫的房子从第一个房子到倒数第二个房子。

如果我们不打劫第一个房子，那么我们就可以打劫最后一个房子，可打劫的房子从第二个房子到最后一个房子。

实际上，对于上述两种情况，由于有了打劫的房子的范围，我们只需要对于打劫的范围内的房子用第198题的方式打劫就好了，因为我们已经
分情况（划分打劫区间）考虑了首尾相邻的问题，所以对于这两种情况我们分别求出在对应区间内打劫到的最大值，然后对于这两个结果
再取一个最大值就是最终的结果了。

代码如下：

```
class Solution {
public:
    int robHouses(vector<int>& nums, int start, int end) {                  //打劫区间为[start, end]（注意左右都是闭）时可打劫到的最大收益，这部分和198题一样
        vector<int> dp(nums.size());
        dp[start] = nums[start], dp[start + 1] = max(nums[start], nums[start + 1]);      //确定边界情况
        for(int i = start + 2; i <= end; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);                  //打劫到第i个房子时的最大值为（不打劫第i个房子，打劫第i个房子）两种打劫方案中的较大值
        }
        return dp[end];                                          //dp[end]就是[start, end]区间能打劫到的最大值
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {                                    //几个特殊情况先特判一下
            return 0;
        }
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robHouses(nums, 0, n - 2), robHouses(nums, 1, n - 1));          //（打劫第一个房子，不打劫第一个房子）两个方案中的较大值就是最终能打劫到的最大值
    }
};
```