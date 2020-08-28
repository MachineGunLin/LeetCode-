/*
0~n有n+1个数，可以根据等差数列求和公式快速算出总和。减去nums数组的n个数，就能在线性时间内算出缺少了哪个数。
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectSum = n * (n + 1) / 2;
        for(auto &x : nums) {
            expectSum -= x;
        }
        return expectSum;
    }
};
