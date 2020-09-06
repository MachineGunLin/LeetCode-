# LeetCode第34场双周赛



# 第一题 5491. 矩阵对角线元素的和
![](https://img2020.cnblogs.com/blog/2078361/202009/2078361-20200906085412827-590579285.png)

注意正中间的元素会加两次，需要减掉一次。

```
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += mat[i][i];
            sum += mat[i][n - 1 - i];
            if(i == n - 1 - i) {
                sum -= mat[i][i];
            }
        }
        return sum;
    }
};
```

# 第二题 5492. 分割字符串的方案数
![](https://img2020.cnblogs.com/blog/2078361/202009/2078361-20200906085517670-750866870.png)

s的长度最大可能达到10^5,如果两重循环枚举两个切割点，肯定会超时。

由于三个字符串中都只统计1的个数，所以我们可以看一下s里有多少个1，然后想办法直接计算。
遍历一遍s，计算1出现的次数，记为sum。
首先，如果sum % 3 != 0，那就无解了，没法让三个字符串中1的个数相等，返回0；
第二种特殊情况就是sum == 0,也就是说字符串s中没有1，那不管我们怎么切割，三个字符串中1的个数都是0，也是一种相等的情况，
切割点有n - 1个，s1和s2中的切割点有n-1种情况，s2和s3中的情况就只有n-2种了，又因为顺序关系，还要再除以2，所以这种情况下
答案就是(n - 1) * (n - 2) / 2;
其他情况就是，sum % 3 == 0 && sum != 0，这样是有切割方法可以让三个字符串中1的个数相等且都不是1的，第一个切割点就是满足当前位置
1的前缀和是sum / 3,第二个切割点就是当前位置1的前缀和是sum * 2 / 3,把这两个切割点的方案做一个乘积，就是第三种情况的切割方案数。

```
int mod = 1e9 + 7;
using LL = long long;
class Solution {
public:
    int numWays(string s) {
        LL n = s.size();
        LL sum = 0;                              // 计算s中1的个数
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                ++sum;
            }
        }
        if(sum % 3 != 0) {                       
            return 0;
        }
        if(sum == 0) {
            return ((n - 1) * (n - 2) / 2) % mod;
        }
        vector<int> ones(n, 0);                   // 计算前缀和，ones[i]表示s[0]~s[i]中有多少个1
        LL s1 = 0, s2 = 0;                        // s1和s2分别表示第一和第二个切割点的可选位置数量
        ones[0] = s[0] == '1' ? 1 : 0;
        if(sum == 3 && ones[0] == 1) {
            ++s1;
        }
        for(int i = 1 ; i < n; ++i) {
            if(s[i] == '1') {
                ones[i] = ones[i - 1] + 1;
            } else {
                ones[i] = ones[i - 1];
            }
            if(ones[i] == sum / 3) {                        // 找到一个s1的可选位置
                ++s1;
            }
            if(ones[i] == sum * 2 / 3) {                   // 找到一个s2的可选位置
                ++s2;
            }
        }
        return s1 * s2 % mod;
    }
};
```

# 第三题 5493. 删除最短的子数组使剩余数组有序
![](https://img2020.cnblogs.com/blog/2078361/202009/2078361-20200906093656555-118739741.png)

由于子数组是连续的，所以删除子数组有三种情况：从开头删除一段连续的子数组使剩下的元素非递减、从结尾删除一段连续的子数组
使剩下的元素非递减、从中间删除一段连续的子数组使剩下的元素非递减。

删除就对应了保留，三种删除情况分别对应：保留结尾的一段连续的非递减子数组、保留开头的一段连续的非递减子数组、保留两端
子数组（分别在开头和结尾），使得它们连接起来的子数组也是非递减的。

我们对这几种情况分别讨论，首先，保留结尾的一段连续的非递减子数组，我们就从结尾开始往前遍历就好了。
```
int n = arr.size(), right = n - 1;
for(int i = n - 1; i >= 1; --i) {
    if(arr[i] >= arr[i - 1]) {
        --right;
    } else {
        break;
    }
}
```
遍历结束后，我们就找到了结尾的最长非递减子数组：arr[right~n-1]。

然后我们再看第二种和第三种保留情况，这两种情况有个共同点，都保留了开头的一段连续的非递减子数组，我们可以从开头找连续的子数组，
然后对于每一个连续的子数组，看看之前找到的结尾非递减子数组arr[right~n-1]里有没有连续非递减子数组可以和当前的（开头的）子数组
构成一个连续非递减子数组，有就更新一下答案，没有就算了（表示只保留开头的一段连续子数组），如果出现下一个元素比当前最后一个元素大，
说明当前的开头连续子数组已经不是非递减了，退出循环，返回答案。

```
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), right = n - 1;                  // right记录结尾的最长非递减子数组的开头位置
        for(int i = n - 1; i >= 1; --i) {
            if(arr[i] >= arr[i - 1]) {
                --right;
            } else {
                break;
            }
        }
        int res = n - right;                               // 结尾的非递减子数组为arr[right~n-1]，则需要删掉n-right个元素
        for(int i = 0; i < n; ++i) {
            if(i == 0 || arr[i] >= arr[i - 1]) {           // 当前还能组成一个更长的（开头的）连续非递减子数组
                while(right < n && (i >= right || arr[i] > arr[right])) {            // 寻找arr[right~n-1]这个非递减子数组里有没有子数组可以和开头的子数组组成更长的非递减子数组
                    ++right;
                }
                res = max(res, i + 1 + n - right);                        // 更新一下答案，当前这个答案只是我们保留的元素个数，并不是题目要求的删除的元素个数
            } else {                                    // 当前的开头子数组已经不是非递减了，break
                break;
            }
        }
        return n - res;                              // 数组元素个数减去保留的元素个数，就是要删除的元素个数
    }
};
```

# 第四题 5494. 统计所有可行路径
![](https://img2020.cnblogs.com/blog/2078361/202009/2078361-20200906101925702-1653282415.png)
![](https://img2020.cnblogs.com/blog/2078361/202009/2078361-20200906101938781-1057332153.png)

动态规划+记忆化搜索，参考[零神的题解](https://www.bilibili.com/video/BV1vk4y127bx?p=5)

用一个二维数组dp表示方案数，dp[position][rest]表示从城市position出发，在还剩余油量为rest的情况下，到达终点finish
的方案数。最开始在start城市，剩余油量为fuel，因此答案就是dp[start][fuel]。
有了状态表示之后，我们需要确定状态转移方程，首先需要枚举从当前城市出发可以去哪些城市，实际上，只要从当前城市出发到达下一个
城市的开销cost是小于等于当前剩余油量rest的（因为题目要求任一时刻剩余油量都需要大于等于0），我们就可以去。因此我们可以用dfs
爆搜一下能去哪些城市，从而更新dp数组。
如果我们从当前城市positon出发，可以去到城市i（i从0~n-1枚举并且position!=i,因为不能还呆在当前城市，另外cost <= res)，那么
我们可以更新dp[position][rest]，dp[position][rest]就是其他所有城市（从position出发能到的下一个城市）的方案数进行求和。
即dp[position][rest] = sum(dp[i][rest - abs(locations[position] - locations[i])])。
另外，如果当前城市position已经是终点，即position==finish，那么要对dp[position][rest]加一，因为到达了这个城市，可以选择停下，
这也是一种方案。

```
int mod = 1e9 + 7;
class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<int>& locations, int pos, int finish, int rest) {
        if(dp[pos][rest] != -1) {                  // 记忆化搜索，已经计算过这个方案数了，直接返回。 
            return dp[pos][rest];
        }
        dp[pos][rest] = 0;                        // 没计算过，先假设方案数为0
        int n = locations.size();
        for(int i = 0; i < n; ++i) {
            if(pos != i) {
                int cost = abs(locations[pos] - locations[i]);            // 计算到达下一个城市的成本
                if(cost <= rest) {                                        // 剩余油量大于成本时才可以去下一个城市
                    dp[pos][rest] = (dp[pos][rest] + dfs(locations, i, finish, rest - cost)) % mod;      // 更新当前方案数，当前方案数是（所有）下一个城市到达终点的方案数的和
                } 
            }
        }
        if(pos == finish) {
            dp[pos][rest] = (dp[pos][rest] + 1) % mod;
        }
        return dp[pos][rest];                                    // 返回当前城市，以剩余油量到达终点的不同的方案数。
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp = vector<vector<int>>(locations.size(), vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }
};
```