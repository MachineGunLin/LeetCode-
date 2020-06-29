/*
用一个数组记录各个位数的变化，通过低位+1，观察各个位数的变化。
注意一下如果最高位因为进位导致多了一位，需要将进位（只可能是1 push_back()进数组）
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());            //由于push_back()只能将数加在后面，因此要先翻转数组
        int carry = 1;                                    //carry表示进位，初始为1，因为题目要我们加一
        for(auto& digit : digits) {                       //从低位到高位确定每一位的数字
            carry += digit;
            digit = carry % 10;
            carry /= 10;
        }
        if(carry == 1) {                                  //如果到了最高位还是有进位，需要将进位1压入数组
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());            //再翻转回来
        return digits;
    }
};
