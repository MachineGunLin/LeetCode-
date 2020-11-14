/*
因为子数组是连续的，所以判断连续的子数组的和时，我们往往开一个前缀和数组预处理出所有数的前缀和，这样能够降低求子数组的和的时间复杂度。

这题需要单独处理k为0的情况，由于数组所有元素都是非负数，所以当k为0时，如果存在两个相邻的数的值都为0，则返回true，否则返回false。

使用前缀和判断是否存在满足条件的子数组时，只需从小到大枚举子数组的长度，然后再在内层循环内枚举子数组的长度，然后使用前缀和计算区间和的公式计算是否存在子数组的和满足条件即可。有点类似区间dp，hh。
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) {
            for(int i = 0; i < n; ++i) {
                if(nums[i] == 0 && i + 1 < n && nums[i + 1] == 0) {
                    return true;
                }
            }
            return false;
        }
        vector<int> preSum(n + 1, 0);                  // preSum是前缀和, preSum[i]表示nums[0] + nums[1] + ... + nums[i - 1]
        for(int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        for(int len = 2; len <= n; ++len) {             // 从小到大枚举子数组的长度，注意，题目要求子数组的长度至少是2
            for(int i = 1; i + len - 1 <= n; ++i) {      // 枚举子数组的起点，i + len - 1是子数组的终点
                int j = i + len - 1;
                if((preSum[j] - preSum[i - 1]) % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
