/*
对数组排序，如果存在重复元素，
遍历数组时必能发现两相邻元素相等，
你懂我意思吧？
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
