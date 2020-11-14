/*
要按照概率随机选择一个数，可以将数组的值看作一个区间上的长度，比如题目给的例子，当w = [1, 3]时，我们可以假设有一个一维的区间，区间前1/4是第0个数，区间的后3/4是第1个数。

区间总长度4也就是w数组所有数的和。

我们可以在总长度范围（0～4）内随机选择一个数，假设这个数是0~1，那么就返回0，如果这个数是1～4，那么就返回1。
这样就解决了按照概率随机返回的问题。

但是怎么判断我们随机选择的数该返回什么值呢？
这里需要用到前缀和，比如上面的例子w = [1, 3]，我们可以得到前缀和preSum = [0, 1, 4]（计算前缀和时，一般前面要预留一个0，也就是w[0] + ... + w[i]的前缀和实际上是preSum[i + 1]，这是有前缀和的计算公式决定的)。

我们在总长度范围内随机取的数在区间内处于哪一个前缀和的范围内，就返回那个前缀和对应的下标，比如我们取到随机数oneRandNum = 2，那么在前缀和区间里第一个大于等于它的前缀和是下标为2（在原数组中下标为1）的前缀和4，这时我们需要返回前缀和为4的那个下标2（在原数组中下标为1），所以我们需要返回**lower_bound(preSum.begin() + 1, preSum.end(), oneRandNum) - preSum.begin() - 1**

有点绕hh，画个图就理解了～
*/

class Solution {
public:
    vector<int> preSum;
    int n;

    Solution(vector<int>& w) {
        n = w.size();
        preSum.resize(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + w[i - 1];
        }
    }
    
    int pickIndex() {
        int oneRandNum = rand() % preSum[n] + 1;                        // 取一个随机数，+1是为了将随机数映射到范围[1, 2, ... preSum[n]]内
        return lower_bound(preSum.begin() + 1, preSum.end(), oneRandNum) - preSum.begin() - 1;     // 找到第一个大于等于oneRandNum的前缀和在原数组中对应的下标，就是答案
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
