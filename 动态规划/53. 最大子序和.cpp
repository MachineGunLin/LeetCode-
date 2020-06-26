/*
要求一个最大子序和，思路是：假设每个以第i个元素结尾的子数组的最大值为f(i),那么我们要求的最大子序和就是遍历所有的i，
得到以i结尾的最大的f(i)， 显然f(i) = max{f(i - 1), nums[i]}，也就是说以第i个元素结尾的子数组的最大值为
以第i-1元素结尾的子数组的最大值加上nums[i] 与 nums[i]中的较大值。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for(auto num : nums) {
            if(sum >= 0) {
                sum += num;
            } else {
                sum = num;
            }
            res = max(res, sum);
        }
        return res;
    }
};
