/*
直接把整数 x 转换成一个字符串 s，
然后反转字符串，如果是正数，则翻转整个字符串 std::reverse(s.begin(), s.end())
如果是负数，则不翻转负号 std::reverse(s.begin() + 1, s.end())
然后再把字符串 s 转换成long类型 res
由于题目要求，最后再判断一下res是否在32位int范围内，如果不在，就返回0。
*/

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        long res;
        if(x < 0) {
            std::reverse(s.begin() + 1, s.end()); 
        } else {
            std::reverse(s.begin(), s.end());
        }
        res = stol(s);                              // string to long
        if(res < 2147483647 && res > -2147483648) {   //32位int范围
            return res;
        } else {
            return 0;
        }
    }
};


/*
要翻转一个整数，常见的方法是秦九韶算法。
也就是下面的这个while循环，注意这里没有考虑x是负数的情况，
这是因为c++中取余操作，负数取余得到的还是负数，所以这个循环对负数也成立。
负数取余还是负数的例子：-4对10取余结果还是-4（可以理解为和6同余）。
*/

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if(res > INT_MAX || res < INT_MIN) {
            return 0;
        } else {
            return res;
        }
    }
};


/*
不用long long的做法：
在while循环前面先判断是否溢出:
比如向上溢出： 10 * res + x % 10 > INT_MAX
移项之后只需判断 res > (INT_MAX - x % 10) / 10
向下溢出同理, 只需判断 res < (INT_MIN - x % 10) / 10
由于while循环里判断了溢出，所以最后无需再判断溢出了，直接返回res即可。
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            if(res > 0 && res > (INT_MAX - x % 10) / 10) {
                return 0;
            }
            if(res < 0 && res < (INT_MIN - x % 10) / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
