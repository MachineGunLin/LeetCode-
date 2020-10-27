/*
脑筋急转弯问题，每次把n-1个数做加一操作，等价于把剩下的那个数做减一操作（因为我们只考虑所有数相对的值）。

所以，经过若干次操作之后让所有数都相等，就等价于对于所有数都减小到当前数组中最小值的减一操作的次数。
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNums = *min_element(nums.begin(), nums.end());   // minNums是数组中的最小元素
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {     // nums[i]经过nums[i] - minNums次减一操作可以变为minNums
            res += (nums[i] - minNums);
        }
        return res;
    }
};
