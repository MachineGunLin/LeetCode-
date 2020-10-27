/*
题目要求只能用常数空间和线性时间完成这个任务，因此需要用一个比较取巧的做法。

在没有空间限制的情况下，我们会想到对每个值做一个映射，比如用一个哈希表计算每个数出现的次数。但是由于此题对空间进行了限制，
因此我们只能在原数组上进行“映射”，再由观察发现，每个数的值都是1～n内的整数，正好可以将值映射到下标。

所以可以这样：对于一个值`nums[i]`,我们将`nums[nums[i]]`变为负数，这样，一遍扫描之后。再进行第二遍扫描。如果某个数`j`未在数组中出现过，这`nums[j - 1]`为正数。
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int pos = abs(nums[i]) - 1;                 // 由于之前nums[i]可能已经变为负数，因此取值时要加上绝对值，减一是因为数组下标从0开始
            if(nums[pos] > 0) {                        // 如果nums[pos]大于0，将它改为负数
                nums[pos] = -nums[pos];
            }
        }
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            if(nums[i] > 0) {                        // 如果nums[i]是正数，说明原数组不存在i + 1，因为如果存在i + 1,那么nums[i]在第一遍扫描的时候会被修改为负数
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
