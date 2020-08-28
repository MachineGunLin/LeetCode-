/*
我们知道两个相同的数异或之后就为0，所以对于nums数组中的所有数，异或之后的结果就是那两个只出现一次的数异或的值。

这个值必然不为0（因为这两个数是不同的），所以这个数的二进制表示里，从低位往高位必然有一位1，这一位是1，说明这两个数
在这一位的二进制表示不同（因为这个数是异或得到的），我们可以以与这一位的1与的结果为1还是为0，把nums数组的元素
分为两组，则这两个不同的数必然被分在不同的组。 又由于相同的数异或为0，所以同一组的数全部进行异或操作，最后两组剩下的
值就分别是这两个不同的数了。
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);                        // 分为两组
        int sum = 0;                                  // sum是nums所有元素异或的结果
        for(int i = 0; i < nums.size(); ++i) {
            sum ^= nums[i];
        }
        int firstOne = sum & (-sum);                  // 得到最低位的1，sum & (-sum)这是一个常见的技巧
        for(int i = 0; i < nums.size(); ++i) {
            if(firstOne & nums[i]) {                  // 如果和firstOne相与为1，分到第一组（并且第一组所有元素进行异或操作）
                res[0] ^= nums[i];
            } else {                                  // 否则到第二组（并且第二组所有元素进行异或操作）
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};
