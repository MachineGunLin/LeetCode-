// 注意s.substr(index, size) 指的是字符串s从第index个位置开始，长度为size的子串。

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }
        if(needle.size() == 0) {
            return 0;
        }
        for(int i = 0; i <= haystack.size() - needle.size(); ++i) {
            if(haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
