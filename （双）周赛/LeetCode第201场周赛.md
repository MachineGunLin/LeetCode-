# LeetCode第201场周赛

# 第一题 1544. 整理字符串
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200817140210629-1083806293.png)

简单模拟，用一个字符串res记录结果，然后遍历原字符串，如果res为空或者当前字母与res的最后一个字母不是同一个字母的大小写形式，
就把当前字母加入到res字符串中，否则，删除res的最后一个字母。

```
class Solution {
public:
    string makeGood(string s) {
        string res;
        int size = s.size();
        for(int i = 0; i < s.size(); ++i) {
            if(res.empty()) {
                res += s[i];
            } else {
                if((res.back() + 32 == s[i]) || (res.back() - 32 == s[i])) {
                    res.pop_back();
                } else {
                    res += s[i];
                }
            }
        }
        return res;
    }
};
```

# 第二题 1545. 找出第 N 个二进制字符串中的第 K 位
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200817141846362-57755381.png)

这题n最大20，可以直接开一个数组，算出2到n的所有字符串（1不用算），然后返回n的第k个字符即可。

```
class Solution {
private:
    vector<string> s = vector<string>(21);
public:
    char findKthBit(int n, int k) {
        s[1] = "0";
        for(int i = 2; i <= n; ++i) {
            string invertLastS = "";                  //invertLastS是上一个字符串按位取反的字符串
            for(int j = 0; j < s[i - 1].size(); ++j) {
                if(s[i - 1][j] == '0') {
                    invertLastS += '1';
                } else {
                    invertLastS += '0';
                }
            }
            s[i] = s[i - 1] + "1" + string(invertLastS.rbegin(), invertLastS.rend());
        }
        return s[n][k - 1];
    }
};
```

# 第三题 1546. 和为目标值的最大数目不重叠非空子数组数目
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200817142051352-388798740.png)

数据范围是10^5，所以O(n^2)的算法是不能接受的，必须在O(n)的时间复杂度内计算出来，因此考虑前缀和。

我们遍历一遍数组，同时用一个变量sum记录从数组开头加到当前位置的和，然后我们需要寻找以当前位置作为某段子数组的结尾，是否可以形成
和为target的子数组，这样我们就需要子数组的开头，所以我们需要一个哈希表map<int, int>计算每个位置的前缀和。

所以如果我们遍历到某个位置i，当前和为sum，如果哈希表中存在一个大于0的startPos，Hash[sum - target] = startPos, 那么我们就找到了一个
子数组nums[startPos + 1 ... i]，使得这个子数组的和为target。
因为从开头到startPos的和为sum - target, 从开头到i的和为sum, 所以从startPos + 1 ~ i的和为target。

这还不够，因为我们需要的是和为target的**最大数目**不重叠非空子数组，所以我们需要记录前缀和为sum的最后位置，也就是说，如果两个数p和q
的前缀和都为sum - target，且p在q的位置之后，那么我们加上的子数组应该是p + 1 ~ i 而不是q + 1 ~ i。
这里有贪心的思想在里头，因为我们取一个长度较短的子数组，前面就能留出长度更长的数组，这样数目肯定会更大一些，最起码也是一样大。

因为最终答案是子数组的个数，所以我们用一个数组dp来记录答案，dp[i]表示nums数组的前i个数字（i从1开始）中能找到的和为target的非重叠子数组的最大数目，
这样dp[size]（size是nums数组的大小）就是最终的答案。

我们遍历一遍nums数组，首先，前i个数字的和为target的非重叠子数组的最大数目肯定不小于前i-1个数字的和为target的非重叠子数组的最大数目。
所以dp[i] = max(dp[i], dp[i - 1]);

然后求出从开头到当前位置的前缀和sum: sum += nums[i - 1]; 
然后去哈希表寻找是否存在一个startPos,使得Hash[sum - target] = startPos，如果startPos大于0，
说明找到了一个位置startPos,使得startPos + 1 ~ i的子数组的和为target,那么dp[i] = max(dp[i], dp[startPos] + 1); （+1表示多了一个子数组）
如果没找到，但是sum == target，说明从开头位置到当前位置的和为一个target，那么dp[i] = max(dp[i], 1);
最后当然要在哈希表里记录一下前缀和为sum的最后位置：Hash[sum] = i;

代码如下：

```
const int N = 1e5 + 10;
vector<int> dp(N);
map<int, int> Hash;
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum = 0;
        int size = nums.size();
        fill(dp.begin(), dp.begin() + size + 1, 0);
        Hash.clear();
        for(int i = 1; i <= size; ++i) {
            dp[i] = max(dp[i], dp[i - 1]);
            sum += nums[i - 1];    
            int startPos = Hash[sum - target];
            if(startPos > 0) {
                dp[i] = max(dp[i], dp[startPos] + 1);
            } else if(sum == target) {
                dp[i] = max(dp[i - 1], 1);
            }
            Hash[sum] = i;
        }
        return dp[size];
    }
};
```

# 第四题 1547. 切棍子的最小成本
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200817153413027-900016544.png)
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200817153424741-1045596943.png)

区间dp问题。
设cuts数组的大小为m，也就是说一共切m刀，最终会得到m+1段木棍，我们要求出切割m+1段木棍的最小代价。
我们可以反过来看，已经有了m+1段木棍，我们转而去求将所有木棍合并为一段木棍的代价。
这样好理解一点，合并的代价和题目定义的切割的代价是相同的，就是两端小木棍的长度之和。

由于cuts的大小最大为100，所以我们可以开一个二维数组dp[105][105]。
dp[i][j]的定义就是合并第i段木棍和第j段木棍为一根木棍的最小代价。1 <= i, j <= m。 （这里m是木棍的总数量）
最终的答案就是dp[1][m],也就是将所有木棍合并为一根木棍的最小代价和。

对于dp[i][j]，如果i和j中间有一个切点k，则第i段到第j段木棍的总长度我们可以理解为是**第i段木棍到第k段木棍（视为一段）**
和**第k+1段木棍到第j段木棍（也视为一段）**这两段木棍合并而来的。

则**dp[i][j] 就是  dp[i][k] + dp[k + 1][j] + 合并这两段木棍的代价**
合并这两段木棍的代价好算，就是这两段木棍的长度和，也就是第j段木棍右边的切点和第i段木棍左边的切点之差,即cuts[j] - cuts[i - 1];

这样我们就得到了状态转移方程，我们可以枚举每次合并的木棍区间长度（也就是合并多少根木棍），然后还要枚举（当前合并范围内的）第一根木棍i，
通过第一根木棍加上木棍区间长度，得到当前合并范围的最后一根木棍j，然后在这两个木棍范围内枚举切点k。
比如，现在枚举到以第i个木棍为第一根木棍，第j个木棍作为最后一个木棍，我们需要求出合并第i, i + 1, i + 2.....j根木棍的总代价，
我们需要枚举切点为i, i + 1, ......j - 1， 然后分别计算如果k是这些切点的时候总代价是多少，总代价就是合并i, i + 1,....k 和 合并k + 1, k + 2, ... j
的代价加上第i根木棍，第i+1根木棍，。。。。第j根木棍的总长度和(cuts[j] - cuts[i - 1])。
如果计算出来的代价dp[i][k] + dp[k + 1][j] + cuts[j] - cuts[i - 1]比之前记录的代价dp[i][j]小，说明我们找到了一个**“更好”**的切点，
如果（优先）以这个点切割木棍，能够得到更小的代价。

就这样，枚举完所有可能的合并区间，计算完所有合并的代价之后，最终返回dp[1][m],即合并第1根木棍，第2根木棍，。。。。第m根木棍（这里m为总的木棍数量）
的最小代价。

代码如下：

```
const int N = 105;
int dp[N][N];
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);                        //把两个端点也加进去，当作“切点”
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size() - 1;                 //不加两个端点的时候，木棍数量是cuts.size() + 1,现在cuts加了两个端点，所以木棍数量m是cuts.size() - 1
        for(int i = 1; i <= m; ++i) {            //预处理所有木棍的合并方案，-1表示这个方案不可行
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = -1;
            }
        }
        for(int i = 1; i <= m; ++i) {            //合并第i根木棍到第i根木棍的代价为0，因为就一根木棍，没什么好合并的
            dp[i][i] = 0;
        }
        for(int len = 1; len < m; ++len) {          //枚举合并的区间范围
            for(int i = 1; i <= m; ++i) {           //i是当前合并范围的第1根木棍，从1枚举到m
                int j = i + len;                    //i+len就是当前合并范围内的最后一根木棍
                if(j > m) {                         //一共就m根木棍，超过了就break
                    break;
                }
                for(int k = i; k < j; ++k) {         //枚举切点，从i ~ j - 1
                    if(dp[i][k] != -1 && dp[k + 1][j] != -1) {            //如果当前切割方案可行
                        int cost = dp[i][k] + dp[k + 1][j] + cuts[j] - cuts[i - 1];      
                        if(dp[i][j] == -1 || dp[i][j] > cost) {            //且这样切割的代价更小
                            dp[i][j] = cost;                              //则我们更新切割（合并）第i~j根木棍的代价
                        }
                    }
                }
            }
        }
        return dp[1][m];                        //合并第1～m根木棍的代价就是最终答案
    }
};
```