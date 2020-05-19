/*
思路：
双指针：
最好的情况就是原字符串无需删除字符就是回文的。
如果遇到某两个字符s[low]和s[high]不相等，这时就要考虑删除s[low]或者s[high]了，
额外写一个验证字符串s的low ~ high部分的子串是否是回文的函数checkPalindrome。
这样当我们在碰到s[low] != s[high]时就只需判断字符串s的 low + 1 ~ high 或者
low ~ high - 1部分是否是回文的了，如果其中一个是回文的，说明只需要删除一个字符就可以
让字符串s是回文的。
*/

class Solution {
public:
    bool checkPalindrome(string& s, int low, int high) {
        for(int i = low, j = high; i < j; ++i, --j) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high) {
            if(s[low] == s[high]) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low + 1, high) || checkPalindrome(s, low, high - 1);
            }
        }
        return true;
    }
};
