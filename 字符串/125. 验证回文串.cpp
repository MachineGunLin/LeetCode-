class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto& c : s) {
            if(isalnum(c)) {              //isalnum()用来判断一个字符是否是数字或者字母
                str += tolower(c);
            }
        }
        string reverseStr(str.rbegin(), str.rend());
        return str == reverseStr;
    }
};
