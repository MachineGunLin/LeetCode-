/*
出现两次的数字异或为0，也就是相互抵消了。
任何数和0异或还是原来的结果。
所以把所有数做异或，剩下来的就是只出现了一次的数字。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
