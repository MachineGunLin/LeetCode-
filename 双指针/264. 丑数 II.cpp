/*
因为丑数的因子只有2，3，5，所以我们可以用三指针指向当前最大的三个丑数，下一个丑数必然是当前最大的三个丑数×2、×3、×5得到的三个数中
最小的那一个。 得到新的丑数之后，做了乘法的那个指针就往前移动，这样三个指针时刻指向最大的三个丑数。
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums;
        uglyNums.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; ++i) {
            int p2Ugly = uglyNums[p2] * 2;
            int p3Ugly = uglyNums[p3] * 3;
            int p5Ugly = uglyNums[p5] * 5;
            int newUgly = min(p2Ugly, min(p3Ugly, p5Ugly));            // 下一个丑数是这三个数里最小的那个
            uglyNums.push_back(newUgly);
            if(newUgly == p2Ugly) {
                ++p2;
            }
            if(newUgly == p3Ugly) {
                ++p3;
            }
            if(newUgly == p5Ugly) {
                ++p5;
            }
        }
        return uglyNums[n - 1];
    }
};
