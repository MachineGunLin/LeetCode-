/*
要判断是否会出现无限循环小数，就需要找循环节。

如果出现了循环节，会出现这样一种情况：被除数除以除数的商，在之前已经出现过了，比如2 / 3，2比3小，借位，20 / 3 = 6 ... 2, 然后商又是6，6在之前出现过了，所以我们知道循环节就是6。

最终结果就是0.(6)。

要记录之前已经出现过的商，我们就需要一个哈希表记录之前出现过的商，我们可以不断做除法，直到整除或者出现循环节。

这道题测试用例有可能numerator是-2147483648(-2^31)，而denominator是-1，这样商就是2147483648（2^31)，而int的最大值是2^31-1,因此可能会爆int，所以我们用long long来存储中间计算结果。
*/


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        typedef long long LL;
        LL x = numerator, y = denominator;
        if(x % y == 0) {                        //如果整除，直接返回结果
            return to_string(x / y);
        }
        string res;
        if((x < 0) ^ (y < 0)) {                  //如果x和y中有且仅有1个是负数，则最终的商是负数
            res += '-';
        }
        x = abs(x), y = abs(y);
        res += to_string(x / y) + '.';            //计算出整数部分，不要忘了加上小数点
        x %= y;                                   
        unordered_map<LL, int> hash;              //哈希表记录当前的商在res字符串中出现的位置，这是为了我们之后判断重复和截取循环节
        while(x != 0) {
            hash[x] = res.size();                 //记录下当前这个商在res中的位置，方便之后根据res的下标截取循环节
            x *= 10;                              //根据除法规则，被除数比除数小，向低位借位
            res += to_string(x / y);              
            x %= y;
            if(hash.count(x) != 0) {              //出现重复的商，说明找到了循环节，把循环节加上括号
                res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';      //res.substr(0, hash[x])是不循环部分，加上带括号的循环节，就是最终答案
                break;
            }
        }
        return res;
    }
};
