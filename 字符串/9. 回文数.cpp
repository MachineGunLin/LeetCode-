/*
如果转换成字符串，就很好判断。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        } else {
            string s = to_string(x);
            for(int i = 0; i < s.size() / 2; i++) {
                if(s[i] != s[s.size() - 1 - i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
有更简洁的写法：整数转换成字符串之后，直接判断这个字符串是否和它的反转字符串相等。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
};
