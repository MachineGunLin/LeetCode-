/*
计算斐波那契数列，直接根据公式递推一下就好了。
*/

class Solution {
public:
    int F[31];

    int fib(int N) {
        memset(F, 0, sizeof F);
        F[1] = 1, F[2] = 1;
        for(int i = 3; i <= N; ++i) {
            F[i] = F[i - 1] + F[i - 2];
        }
        return F[N];
    }
};
