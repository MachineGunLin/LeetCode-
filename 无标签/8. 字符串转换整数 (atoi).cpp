/*
首先过滤掉前缀的所有空字符。
然后要判断一下当前字符是什么，如果是负号，需要记录一下是负号，然后移到下一位。如果是正号则同理。
然后一个while循环求连续的字符所组成的整数的和，注意要在while循环里面判断是否溢出，如果溢出要break，
题目要求如果超过INT_MAX或者INT_MIN就要返回INT_MAX和INT_MIN。
*/

class Solution {
public:
    int myAtoi(string str) {
        int k = 0;
        while(k < str.size() && str[k] == ' ') {          //先过滤掉前缀的空字符
            ++k;
        }
        if(k == str.size()) {                             //如果字符串全是空字符
            return 0;                                     //则返回0
        }
        int minus = 1;                                    //1表示正，-1表示负
        if(str[k] == '-') {                               //如果以负号开头
            minus = -1;                                   //则记录一下minus为-1
            ++k;                                          //k移到下一位
        } else if(str[k] == '+') {                        //如果开头是正号
            ++k;                                          //因为minus已经是1了，所以只需要k移到下一位
        }
        long long res = 0;
        while(k < str.size() && str[k] >= '0' && str[k] <= '9') {
            res = res * 10 + str[k] - '0';
            ++k;
            if(res > INT_MAX) {                           //这里res只有可能是正数，所以只需要判断是否大于INT_MAX
                break;
            }
        }
        res = minus * res;
        if(res > INT_MAX) {
            return INT_MAX;
        }
        if(res < INT_MIN) {
            return INT_MIN;
        }
        return res;
    }
};



/*
不用long long, 用int
*/

class Solution {
public:
    int myAtoi(string str) {
        int k = 0;
        while(k < str.size() && str[k] == ' ') {
            ++k;
        }
        if(k == str.size()) {
            return 0;
        }
        int minus = 1;
        if(str[k] == '-') {
            minus = -1;
            ++k;
        } else if(str[k] == '+') {
            ++k;
        }
        int res = 0;
        while(k < str.size() && str[k] >= '0' && str[k] <= '9') {
            int x = str[k] - '0';
            if(minus > 0 && res > (INT_MAX - x) / 10) {            //向上溢出：res * 10 + x > INT_MAX，移项之后可得 res > (INT_MAX - x) / 10
                return INT_MAX;
            }
            if(minus < 0 && -res < (INT_MIN + x) / 10) {           //向下溢出：res * 10  + x < INT_MIN,考虑到这里的res一定是正数，所以要加上一个符号，移项之后得到 -res < (INT_MIN + x) / 10
                return INT_MIN;
            }
            if(-res * 10 - x == INT_MIN) {                      //由于INT_MAX是2147483647，INT_MIN是-2147483648,也就是说INT_MIN的绝对值比INT_MAX大一
                return INT_MIN;                                 //所以这里需要特判一下，如果 - (res * 10 + x)恰好就是INT_MIN时，返回INT_MIN 
            }   
            res = res * 10 + x;
            ++k;
            if(res > INT_MAX) {
                break;
            }
        }
        res = minus * res;
        if(res > INT_MAX) {
            return INT_MAX;
        }
        if(res < INT_MIN) {
            return INT_MIN;
        }
        return res;
    }
};
