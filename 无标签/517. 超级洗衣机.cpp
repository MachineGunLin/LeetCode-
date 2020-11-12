/*
首先，我们可以把所有洗衣机内的衣服数量累加求和，得到总的衣物的数量sum，假设洗衣机的数量为n，如果sum % n不为0，则无解，因为无法让所有洗衣机的数量相同。

如果sum % n为0，我们求出sum / n的结果avg，也就是最终当所有洗衣机衣服数量相同时每台洗衣机的衣服数量。

题目要我们求让所有洗衣机的衣服数量相等的最小操作步数。由于多台洗衣机可以并行地同时进行运送，所以必存在一台洗衣机，这台洗衣机运送的衣服数量就是答案（最小操作步数）。
也就是说，这台洗衣机运送的衣服数量最多，因为是并行的，所以它运送完所有“需要它运送的衣服的步数”就是运送所有衣服的最小步数的瓶颈（它运送的时候其他洗衣机也可以运送，且结束时间肯定
不会晚于这台洗衣机）。

因此，我们只需要枚举所有洗衣机的运送衣服的数量，取最大运送数量的那台洗衣机，就是我们要求的最小步数。

每台洗衣机要运送的数量可以这样求：
对于每台洗衣机i，都求出它左边所有洗衣机machines[0 ~ i - 1]的目前所有衣服数量leftSum和最终结束时的期望数量i * avg，取max(i * avg - leftSum, 0)就是洗衣机i要从它右边往左边调度的衣服数量。
再求出i右边所有洗衣机machines[i + 1 ~ n]目前所有衣服数量rightSum，和最终结束时的期望衣服数量(n - i - 1) * avg，取max((n - i - 1) * avg, 0)就是洗衣机i要从它左边往右边调度的衣服数量。
那么，洗衣机i要运送的衣服数量就是max(i * avg - leftSum, 0) + max((n - i - 1) * avg, 0)，也就是它所有要往左运送的衣服数量加上所有它要往右运送的衣服的数量之和。

遍历一遍所有洗衣机，求出要运送的衣服数量最大的那台洗衣机要运送的衣服数量，就是最终答案。
*/

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if(sum % n != 0) {
            return -1;
        }
        int avg = sum / n;
        int leftSum = 0, rightSum = sum;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            rightSum -= machines[i];
            int rightToLeft = max(i * avg - leftSum, 0);
            int leftToRight = max((n - i - 1) * avg - rightSum, 0);
            res = max(res, leftToRight + rightToLeft);
            leftSum += machines[i];
        }
        return res;
    }
};
