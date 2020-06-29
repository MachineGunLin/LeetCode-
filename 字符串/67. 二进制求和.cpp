/*
模仿十进制进位写二进制进位。
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i = 0, carry = 0; i < a.size() || i < b.size() || carry != 0; ++i) {      //carry表示进位，当字符串a没走完或字符串b没走完或者进位不为0时就继续计算
            if(i < a.size()) {
                carry += a[i] - '0';
            }
            if(i < b.size()) {
                carry += b[i] - '0';
            }
            res += to_string(carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
