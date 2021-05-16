# LeetCode第241场周赛

## 第一题 5759. 找出所有子集的异或总和再求和

题目链接：[5759. 找出所有子集的异或总和再求和](https://leetcode-cn.com/problems/sum-of-all-subset-xor-totals/)

- 直接爆搜，计算所有可能的子集的异或和`curSum`，加入到答案`ans`里

```c++
class Solution {
private:
    int ans;
    int n;
    
    
public:
    void dfs(vector<int>& nums, int u, int curSum) {
        if(u == n) {
            return ;
        }
        curSum ^= nums[u];
        ans += curSum;
        dfs(nums, u + 1, curSum);
        curSum ^= nums[u];
        dfs(nums, u + 1, curSum);
    }
    
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0, 0);
        return ans;
    }
};
```

## 第二题 5760. 构成交替字符串需要的最小交换次数

题目链接：[5760. 构成交替字符串需要的最小交换次数](https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/)

- 先扫描一遍字符串，计算`1`和`0`的个数`cntOne`和`cntZero`
- 如果能组成合法的交替字符串，那么`cntOne`和`cntZero`的差的绝对值小于`1`
- 贪心，枚举以`1`或以`0`开头的情况，计算最小的交换次数
- 当`1`的个数比`0`的个数多`1`时，开头的元素只能是`1`，反之同理
- 如果`1`和`0`的个数一样多，那就分别枚举`1`和`0`开头的情况，取较小的那个交换次数作为答案

```c++
class Solution {
private:
    int cntOne;
    int cntZero;
    int n;
    int ans;
    
public:
    int minSwaps(string s) {
        n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                ++cntOne;
            } else {
                ++cntZero;
            }
        }
        if(abs(cntOne - cntZero) > 1) {       // 无法组成交替字符串
            return -1;
        }
        if(cntOne > cntZero) {        // 1 的个数比 0 多，则只能以 1 开头
             for(int i = 0; i < n; ++i) {
                if(i & 1) {
                    if(s[i] != '0') {
                        ++ans;
                    }
                } else {
                    if(s[i] != '1') {
                        ++ans;
                    }
                }
            }
            return ans / 2;
        } else if(cntOne < cntZero) {    // 0 的个数比 1 多，则只能以 0 开头
            for(int i = 0; i < n; ++i) {
                if(i & 1) {
                    if(s[i] != '1') {
                        ++ans;
                    }
                } else {
                    if(s[i] != '0') {
                        ++ans;
                    }
                }
            }
            return ans / 2;
        } else {             // 0 和 1 的个数一样多，以 1 或 0 开头都行
            int ans0 = 0, ans1 = 0;
            for(int i = 0; i < n; ++i) {    // 以 0 开头
                if(i & 1) {
                    if(s[i] != '1') {
                        ++ans0;
                    }
                } else {
                    if(s[i] != '0') {
                        ++ans0;
                    }
                }
            }
            for(int i = 0; i < n; ++i) {        // 以 1 开头
                if(i & 1) {
                    if(s[i] != '0') {
                        ++ans1;
                    }
                } else {
                    if(s[i] != '1') {
                        ++ans1;
                    }
                }
            }
            return min(ans0 / 2, ans1 / 2);
        }
        return 0;
    }
};
```

## 第三题 5761. 找出和为指定值的下标对

题目链接：[5761. 找出和为指定值的下标对](https://leetcode-cn.com/problems/finding-pairs-with-a-certain-sum/)

- 很容易想到用两个哈希表分别记录数组中所有元素的个数，不过这样会超时
- 优化：考虑到`nums1`的规模小于`1000`，遍历哈希表的操作又比较慢，因此`nums1`不用哈希表，直接遍历
- `FindSumPairs`时直接初始化`nums2`对应的哈希表即可
- `add`操作也是直接对`nums2`的哈希表进行修改
- `count`操作时，遍历`nums1`，到`nums2`对应的哈希表寻找另一个数的个数，加入到答案`ans`中

```c++
#pragma GCC optimize(3,"Ofast","inline")

class FindSumPairs {
private:
    map<int, int> hash2;         // nums2 数组对应的哈希表，记录所有元素以及它们在 nums2 中的个数
    vector<int> nums1, nums2;
    int n, m;        // 两个数组的大小
    int ans;         // count 的答案
    
public:
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1, nums2 = _nums2;
        n = nums1.size();
        m = nums2.size();
        for(const auto& num : nums2) {      // 初始化哈希表
            ++hash2[num];
        }
    }
    
    void add(int index, int val) {          // nums2 中有元素发生变化，修改哈希表
        --hash2[nums2[index]];
        if(hash2[nums2[index]] == 0) {
            hash2.erase(nums2[index]);
        }
        nums2[index] += val;
        ++hash2[nums2[index]];
    }
    
    int count(int tot) {
        ans = 0;     
        for(int i = 0; i < n; ++i) {       // 遍历 nums1, 到哈希表中寻找另一个数在 nums2 中出现的次数，加入到答案中
            if(nums1[i] >= tot) {
                continue;
            } else {
                ans += hash2[tot - nums1[i]];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
```

## 第四题 5762. 恰有K根木棍可以看到的排列数目

题目链接：[5762. 恰有 K 根木棍可以看到的排列数目](https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/)

- 动态规划
- 从长到短考虑所有木棍的分配位置
- 状态表示：`dp[i][j]`：已经分配了前 `i` 长的木棍（`i`从`1`开始）、并且从左侧看可以看到`j`根木棍的**方案数**
- 状态转移：已经分配了第**1 ~ i**长的木棍，现在考虑第**i + 1**长的木棍
  1. 如果把这根木棍放在当前所有木棍的最左侧，那么从左往右看能看到的木棍数多了一个，因此我们有：**`dp[i + 1][j + 1]` = (`dp[i + 1][j + 1]` + `dp[i][j]`) ;**   表示把第**i + 1**长的木棍放在最左侧的方案数
  2. 如果把这根木棍放在前**1 ~ i**的木棍中任意一个木棍的右侧，从左往右看能看到的木棍数量还是`j`个，那么由于有`i`个可以放木棍的位置，因此我们得到方案数：**`dp[i + 1][j]` = (`dp[i + 1][j]` + `dp[i][j]`;**  表示不把第**i + 1**长的木棍放在最左侧（而是放在比它长的某根木棍的右侧）的方案数
- 最终的答案就是，枚举完前 **n** 根木棍，并且从左往右看能看到 **k** 根木棍的方案数：**`dp[n][k]`**
- 参考资料：[坑神的B站讲解](https://www.bilibili.com/video/BV1w54y1L7Jo#reply4574081600)

```c++
const int mod = 1e9 + 7;
const int maxn = 1005;
using LL = long long;
LL dp[maxn][maxn];

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        memset(dp, 0, sizeof dp);
        dp[1][1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (i - 1)) % mod;    
            }
        }
        return dp[n][k];
    }
};
```

