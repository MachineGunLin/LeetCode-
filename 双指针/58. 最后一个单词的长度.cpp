/*
翻转整个字符串，再用双指针分隔出第一个单词。
注意左指针要先过滤掉前缀的空格，右指针从左指针的位置开始逐渐增加，直到右指针指向空格。
第一个单词的长度就是左右指针的距离之差。
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) {
            return 0;
        }
        reverse(s.begin(), s.end());
        int L = 0;
        while(L < s.size() && s[L] == ' ') {
            ++L;
        }
        int R = L;
        while(R < s.size() && s[R] != ' ') {
            ++R;
        }
        return R - L;
    }
};
