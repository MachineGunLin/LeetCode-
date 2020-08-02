/*
逆序来求字符串，每次把当前数字n对26取余，也就是当前这一位的字母，加到字符串里。

然后数字n整除26，再继续判断是否还能添加字符。
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n != 0) {
            int c = n % 26;            //c是当前字符相对'A'的位移
            if(c == 0) {               //while循环的条件是n不等于0，这里c却等于0，说明，c实际上是26，当前字母为Z
                c = 26;
                n -= 26;
            }
            res += 'A' + c - 1;
            n /= 26;   
        }
        reverse(res.begin(), res.end());            
        return res;
    }
};
