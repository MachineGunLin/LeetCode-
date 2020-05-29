/*
额外开一个数组dp，dp[i]表示小偷到第i个房屋时可以获得的最大收益（到了第i个房屋可以打劫也可以不打劫）
首先需要讨论边界情况，如果nums.size()为0，也就是没有房子，那最大收益就是0。
如果只有一个房子，那最大收益就是打劫这个房子。
如果有两个房子，最大收益就是打劫这两个房子中金额较高的那个房子。
随后从i = 2开始循环，dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); 分别表示到第i个房子时的最大收益是
不打劫这座房子(dp[i - 1])和打劫这座房子(dp[i - 2] + nums[i])中的收益较大者。
同时维护一个变量res要更新为res = max(res, dp[i]);
最后返回res就是最大收益。
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int res = max(dp[0], dp[1]);
        for(int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};


/*
其实最后直接 return dp[size - 1]就行了，我傻了
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};
