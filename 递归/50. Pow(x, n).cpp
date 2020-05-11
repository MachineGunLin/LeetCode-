/*
额外做一个辅助函数myPowHelper(double x, uint32_t n) 这个函数不处理n为负数的情况
如果n为1就返回x本身（递归边界）
另外就是判断n是奇数还是偶数
如果是奇数，就返回half * half * x；
如果是偶数，就返回half * half。
其中half定义为myPowHelper(x, n / 2)；

在函数myPow(double x, int n)
如果n小于0，就返回1.0 / myPowHelper(x, abs(n))
不然就返回myPowHelper(x, n)。
*/

class Solution {
public:
    double myPowHelper(double x, uint32_t n) {
        if(n == 1) {
            return x;
        }
        if(n % 2 != 0) {
            double half = myPowHelper(x, n / 2);
            return half * half * x;
        } else {
            double half = myPowHelper(x, n / 2);
            return half * half;
        }
    }
    double myPow(double x, int n) {
        if(n == 0 || x == 1) {
            return 1;
        }
        if(n < 0) {
            return 1.0 / myPowHelper(x, abs(n));
        }
        return myPowHelper(x, n);
    }
};
