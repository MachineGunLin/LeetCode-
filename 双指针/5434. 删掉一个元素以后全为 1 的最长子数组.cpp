/*
用两个变量start和end指向子数组的开始和结束下标，两个指针只会向右移动，
我们需要寻找这样一个子数组nums[start ~ end]，满足start ~ end之间0的个数不超过1个（1个或0个），
这样我们删去一个元素（0或1）剩下的子数组就满足连续1的条件，然后我们更新长度。
由于此时子数组的长度为end - start + 1,又因为题目要求必须删掉一个元素（就算子数组全部是1，也得删掉一个1），
所以我们得到res = max(res, end - start); 
end - start是子数组长度减1得来的。
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        for(int start = 0, end = 0, zeroNum = 0; end < nums.size(); ++end) {
            if(nums[end] == 0) {
                ++zeroNum;
            }
            while(zeroNum > 1) {
                zeroNum -= !nums[start++];
            }
            res = max(res, end - start);
        }
        return res;
    }
};
