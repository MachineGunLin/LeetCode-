/*
循环，逐位判断每一位是不是1。
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            res += (n >> i & 1) == 1 ? 1 : 0;
        }
        return res;
    }
};
