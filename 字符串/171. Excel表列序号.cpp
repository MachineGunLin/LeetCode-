/*
把每一位的字母转换成1～26的数字，再乘上pow(26, x)，x是当前字符的位置到字符串末尾的距离，比如最后一个字母，就乘上26的0次方，也就是1.
倒数第二个字母，就乘上26的1次方，依次类推。
*/

class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size();
        int res = 0;
        for(int i = 0; i < size; ++i) {
            res += ((int)(s[i] - 'A') + 1) * pow(26, size - i - 1);
        }
        return res;
    }
};
