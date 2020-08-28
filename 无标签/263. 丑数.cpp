/*
如果一个数只包含这几个质因子，那就不断的除以这几个质因子，最后如果只剩下1，就是丑数。
*/

class Solution {
public:
    bool isUgly(int num) {
        while(num >= 5 && num % 5 == 0) {
            num /= 5;
        }
        while(num >= 3 && num % 3 == 0) {
            num /= 3;
        }
        while(num >= 2 && num % 2 == 0) {
            num /= 2;
        }
        if(num == 1) {
            return true;
        }
        return false;
    }
};
