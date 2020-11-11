/*
简单模拟题，直接求num所有因子的和。
这里要注意，num最大可以取到10^8,所以不能是O(n)的时间复杂度（会超时）。
可以借鉴求质数的思想，如果i是num的因子，那么nums / i也是nums的因子，因此我们只需要枚举2～sqrt(num)即可，这样时间复杂度就是O(sqrt(n))。
另外还要注意，枚举的时候，1要单独处理，也是说num为1的情况需要特判，然后枚举因子的时候从2枚举到sqrt(num)即可。
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) {
            return false;
        }
        int sum = 0;                  // sum表示num所有因子的和
        for(int i = 2; i <= num / i; ++i) {      
            if(num % i == 0) {
                sum += i;
                if(i != num / i) {      // 当i不等于sqrt(num)且i是num的因子时，num / i也是num的一个因子
                    sum += num / i;
                }
            }
        }
        if(sum + 1 == num) {            // 这里+1是因为1也是num的一个因子
            return true;
        }
        return false;
    }
};
