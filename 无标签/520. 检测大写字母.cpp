/*
题目给出了正确的大写用法的三种情况，直接根据情况判断即可。

首先要判断第一个字母是否是大写字母，如果第一个字母不是大写字母，那么单词后面如果出现小写字母，这个单词就不是正确的大写用法。

如果第一个字母是大写字母，就判断从第二个字母开始到单词结尾的所有字母是否都是小写字母或者都是大写字母，如果都是小写字母或者都是大写字母，则是正确用法，否则不是正确用法。
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0) {
            return true;
        }
        int n = word.size();
        bool isFirstLetterUpper = isupper(word[0]);           // 判断第一个字母是否是大写字母
        if(isFirstLetterUpper == false) {
            for(int i = 1; i < n; ++i) {
                if(isupper(word[i])) {                        // 如果第一个字母不是大写字母，且单词后面出现了大写字母，则不是正确用法
                    return false;
                }
            }
        } else {
            bool isAllLettersUpper = true;                  // 判断从第二个字母开始到单词结尾的所有字母是否都是 大写 字母
            bool isAllLettersLower = true;                  // 判断从第二个字母开始到单词结尾的所有字母是否都是 小写 字母
            for(int i = 1; i < n; ++i) {
                if(isupper(word[i])) {
                    isAllLettersLower = false;
                } else {
                    isAllLettersUpper = false;
                }
            }
            if(!(isAllLettersUpper || isAllLettersLower)) {    // 如果第一个字母为大写字母，则只有当从第二个字母开始到单词结尾的所有字母都是 大写字母 或 小写字母 时，这个单词才是正确的大写用法
                return false;
            }
        }
        return true;
    }
};
