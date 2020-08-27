/*
用dp[i]记录以nums[i]结尾的最长上升子序列的长度。
遍历数组，对于一个数，从开头遍历到这个数的前一个数，如果存在一个(0 <= j <= i - 1)，nums[j] < nums[i] 且 dp[j] > 1,
则可以考虑更新dp[i] ->  dp[i] = max(dp[i], dp[j] + 1); 表示nums[i]加在nums[j]后面组成了一个新的上升子序列，
当然，如果这个上升子序列的长度不如原来那个以nums[i]结尾的子序列的长度，则dp[i]长度还是原来的子序列的长度。

如果nums[j]比nums[i]大，则nums[i]不能接在nums[j]后面组成一个上升子序列，则dp[i]不变 ->    dp[i] = max(1, dp[i);
1表示nums[i]自己组成了一个上升子序列，显然这个子序列长度为1.

再用一个变量res记录最长的上升子序列的长度，每次更新dp[i]的时候也更新一下res ->   res = max(res, dp[i]);
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        vector<int> dp(size);                              // dp[i]表示以nums[i]作为结尾的最长上升子序列的最大长度
        dp[0] = 1;
        int res = 1;                                       // res是整个数组中最长的上升子序列的长度，最少也是1，表示最长上升子序列只有一个数
        for(int i = 1; i < size; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                } else {
                    dp[i] = max(1, dp[i]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
