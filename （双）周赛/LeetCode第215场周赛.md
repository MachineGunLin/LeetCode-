# LeetCode第215场周赛

# 第一题 1656. 设计有序流
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116201543194-924237195.png)
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116201554418-1728688557.png)

可以开一个字符串数组存放字符串，用一个额外的变量ptr存放ptr的位置，插入新的字符串的时候，检查从ptr开始是否有连续的按照id递增的序列即可。

代码如下：

```
class OrderedStream {
public:
    int n;
    int ptr;
    vector<string> stream;
    
    OrderedStream(int _n) {
        n = _n;
        ptr = 1;                              
        stream = vector<string>(n + 1, "");                  // 字符串数组中所有字符串最初都为空
    }
    
    vector<string> insert(int id, string value) {
        stream[id] = value;
        if(stream[ptr] == "") {            // 如果插入一个新字符串，但id=ptr的字符串为空，则返回一个空的字符串数组
            return {};
        }
        vector<string> res;
        int last = ptr;                   // last记录更新后的ptr的位置
        for(int i = ptr; i <= n; ++i) {
            if(stream[i] != "") {      
                res.push_back(stream[i]);
            } else {                      // 找到一个空的位置，则更新last
                last = i;
                break;
            }
        }
        if(stream[last] != "") {
            ptr = last + 1;
        } else {
            ptr = last;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
```

# 第二题 5603. 确定两个字符串是否接近
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116202105805-2145538431.png)
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116212237765-1928552523.png)

根据题意，两个字符串接近，则满足这些条件：（1）两个字符串中不同的字母的个数相同；（2）如果给所有的字母统计出现次数，则如果某字符串中有出现次数为x的字母y个，则另一个字符串也必然有y个出现次数为x的字母；（3）第一个字符串中的所有字母都在第二个单词内出现过，反之亦然。

第（1）和第（3）点我们可以使用两个unorderd_set<char>进行判断。
第（2）点可以用两个unordered_map<char, int> cnt1, cnt2统计两个字符串中各个字母出现的频率，然后用两个字符串（或数组）将哈希表中的所有频率拼接为一个字符串，如果原单词word1和word2是“接近”的字符串，则将它们的字母出现频率拼接成的字符串排序之后，这两个排序后的字符串必然是相等的，如果不相等，则它们不接近。这一点很好理解，比如word1里有若干个单词出现次数为：2 1 3 4, word2里有若干个单词出现次数为：1 2 4 3,那么它们的出现次数拼接的单词排序之后都是1234，所以这两个单词是接近的。

代码如下：

```
class Solution {
public:
    unordered_set<char> hash1, hash2;            // 计算两个单词中不同单词的个数
    unordered_map<char, int> cnt1, cnt2;         // 统计两个单词中不同字母出现的次数
    
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {      // 如果两个单词长度不同，那么它们不接近
            return false;
        }
        for(auto &c : word1) {
            hash1.insert(c);
            ++cnt1[c];
        }
        for(auto &c : word2) {
            hash2.insert(c);
            ++cnt2[c];
        }
        for(auto &c : hash1) {
            if(hash2.count(c) == 0) {            // 如果第一个单词有第二个单词没有出现过的字母，则它们不接近
                return false;
            }
        }
        for(auto &c : hash2) {
            if(hash1.count(c) == 0) {           // 如果第二个单词有第一个单词没有出现过的字母，则它们不接近
                return false;
            }
        } 
        string fre1, fre2;                      // fre1和fre2分别是对word1和word2的单词出现的频率拼接得到的字符串
        for(auto &cnt : cnt1) {
            fre1 += to_string(cnt.second);
        }
        for(auto &cnt : cnt2) {
            fre2 += to_string(cnt.second);
        }
        sort(fre1.begin(), fre1.end());
        sort(fre2.begin(), fre2.end());
        if(fre1 != fre2) {
            return false;
        }
        return true;
    }
};
```

# 第三题 5602. 将 x 减到 0 的最小操作数
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116203201331-1132147611.png)

题意要求在数组的两端不断地删除元素，使得删掉的元素的和为x，求最小的删除次数。可以反向思考：求数组中最长的区间和为sum - x的区间，其中sum为数组中所有元素的和。

求数组中的区间和可以使用前缀和，然而枚举区间的起点和终点时间复杂度仍会达到O(n^2)，对于10^5的区间长度是无法接受的。

因此我们可以考虑用一个哈希表unordered_map<int, int> mp来记录某个前缀和的下标，mp[i] = j表示前缀和为i的下标为j，即nums[0] + nums[1] + ... nums[j] = i, 我们要找出区间和target = sum - x的区间，而我们在循环的时候可以知道当前位置i的前缀和preSum[i], 因此我们只要知道前缀和为preSum[i] - target的位置，我们就得到了满足题意的一段区间和（也就是说，删掉这段区间的左边部分和右边部分，可以满足题意），然后我们可以用**数组元素的个数 - 这段区间的长度**来更新答案。 使用哈希表记录前缀和的下标，我们可以在O(n)的时间复杂度内求出满足条件的区间和和区间长度。

代码如下：

```
class Solution {
public:
    vector<int> preSum;
    unordered_map<int, int> mp;  // 记录某前缀和的下标
    
    int minOperations(vector<int>& nums, int x) {
        if(nums[0] > x && nums.back() > x) {            // 如果数组的第一个和最后一个元素都大于x，返回-1
            return -1;
        }
        int n = nums.size();
        preSum = vector<int>(n + 1, 0);
        int res = n + 1;
        mp[0] = 0;                      // 0的前缀和为0
        for(int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            mp[preSum[i]] = i;          // i的前缀和为preSum[i]
        }
        int sum = preSum[n];            // sum是数组的所有元素的和
        if(x > sum) {
            return -1;
        }
        if(sum == x) {                  // 删掉所有元素
            return n;
        }
        int target = sum - x;          // 要求的区间和target为sum - x
        for(int i = 1; i <= n; ++i) {
            if(mp[preSum[i] - target] == 0) {           // 之前没记录过前缀和为preSum[i] - left的位置
                if(preSum[i] == target) {               // 如果preSum[i]正好就是target，那么说明我们要删掉i后面的所有元素，可以满足删掉的元素的和为x
                    res = min(res, n - i);
                }
            } else {                               // 之前记录过前缀和preSum[i] - target的位置，也就是说，我们找到了一个满足条件的区间[left ~ i]
                int left = mp[preSum[i] - target];
                res = min(res, n - (i - left));    // 更新最小操作数：区间和为sum - x的区间长度为i - left, 则这段区间左边部分与右边部分的长度为n - (i - left)
            }
        }
        return res;
    }
};
```

# 第四题 1659. 最大化网格幸福感
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116204953659-1422771939.png)
![](https://img2020.cnblogs.com/blog/2078361/202011/2078361-20201116205003667-751222099.png)

状态压缩DP，这里参考了[坑神的视频题解](https://www.bilibili.com/video/BV1c54y1k7Qd?p=5)

用dp[r][i][e][s]表示前r行网格(1<=r<=n)、居住了i个内向的人(0<=i<=introvertsCount)、e个外向的人(0<=e<=extrovertsCount)、并且第r行的居住人的分布状态为s的最大网格幸福感，s的三进制表示是第r行的分布。如果第r行的第j个网格（0<=j<m)没有住人，则s的第j位为0；如果住了一个内向的人，则s的第j位为1；如果住了一个外向的人，则s的第j位为2。
则整个网格的最大幸福感是，处理了前n行，最多居住introvertsCount个内向的人、最多居住extrovertsCount个外向的人，分布状态为s（0<=s<3^m)的网格幸福感的最大值。

有了状态表示，我们要考虑状态转移。

首先，由于我们是按行枚举，所以我们对每一行，都要考虑上一行对这一行的影响（影响指：内向的人数的变化、外向的人数的变化、幸福感的变化）。另外，由于这一行的人员分布状态也可能影响上一行幸福感（比如这一行住了人，会影响到上一行的内向的人和外向的人的幸福感），因此我们在枚举某行的状态和上一行的状态时，要考虑到互相的影响，具体的分析写在下面的注释里。

代码如下：

```
int dp[7][7][7][250];      // dp[r][i][e][s]：前r行使用了i个内向的人、e个外向的人，分布状态为s的最大网格幸福感。 因为一行最多有5个格子，3^5=243,所以分布状态s的范围为0~242
int base[6];               // base表示每一列是3的多少次幂。第0列base[0] = 3^0 = 1, 第1列base[1] = 3^1 = 3, 第2列base[2] = 3^2 = 9, 第3列base[3] = 3^3 = 27，第4列base[4] = 81, 第5列base[5] = 243。 base数组的目的是为了方便为门计算状态s的某一位是多少（0/1/2）
int movIn[250][250], movEx[250][250], mov[250][250];      // movIn[i][j]表示从某行的人员分布状态i转移到下一行的人员分布状态j内向的人数的变化，movEx[i][j]表示外向的人数的变化，mov[i][j]表示幸福感的变化

class Solution {
public:
    int get(int s, int i) {                  // 计算状态s的第i位是多少。 返回值=0：没人    =1：内向的人         =2：外向的人
        s = s % base[i + 1];
        return s / base[i];
    }

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        memset(dp, -1, sizeof dp);
        dp[0][0][0][0] = 0;            
        base[0] = 1;
        for(int i = 1; i <= 5; ++i) {
            base[i] = base[i - 1] * 3;
        }
        int lim = base[m];             // lim是某一行状态的最大值+1，也就是说，某一行的状态s的取值范围为0 ~ lim - 1

        // 预处理出所有状态到其他状态造成的movIn, movEx, mov的变化
        for(int s = 0; s < lim; ++s) {                  // 枚举上一行的状态s
            for(int cur = 0; cur < lim; ++cur) {        // 枚举当前行的状态cur
                movIn[s][cur] = movEx[s][cur] = mov[s][cur] = 0;      // 先假设上一行的状态转移到当前行的状态，内向的人数、外向的人数、幸福感都没有变化
                for(int i = 0; i < m; ++i) {            // 枚举当前行的每一列
                    if(get(cur, i) == 0) {              // 如果当前行的第i列没有住人
                        continue;                       // 那么它对上一行没有任何影响
                    } else {                                       
                        if(get(s, i) == 1) {           // 如果当前位置住了人并且上一行的这个位置住了个内向的人，那么幸福感-30
                            mov[s][cur] -= 30;
                        } else if(get(s, i) == 2) {    // 如果当前位置住了人并且上一行的这个位置住了个外向的人，那么幸福感+20
                            mov[s][cur] += 20;
                        }
                    }
                    if(get(cur, i) == 1) {             // 如果当前位置住了个内向的人
                        movIn[s][cur] += 1;            // 更新内向的人数的变化
                        mov[s][cur] += 120;            // 内向的人的初始幸福感是120
                        if(get(s, i) > 0) {            // 如果上一行这一列位置住了人，那么幸福感-30
                            mov[s][cur] -= 30;
                        }
                        if(i > 0 && get(cur, i - 1) > 0) {    // 如果左边位置住了人，幸福感-30
                            mov[s][cur] -= 30;
                        }
                        if(i + 1 < m && get(cur, i + 1) > 0) {      // 如果右边位置住了人，幸福感-30
                            mov[s][cur] -= 30;
                        }
                    }
                    if(get(cur, i) == 2) {                 // 如果当前位置住了一个外向的人
                        movEx[s][cur] += 1;                // 更新外向的人数
                        mov[s][cur] += 40;                 // 外向的人初始幸福感是40
                        if(get(s, i) > 0) {                // 如果上一行这一列住了个人
                            mov[s][cur] += 20;             // 幸福感+20
                        }
                        if(i > 0 && get(cur, i - 1) > 0) {    // 如果左边位置住了人，幸福感+20
                            mov[s][cur] += 20;
                        }
                        if(i + 1 < m && get(cur, i + 1) > 0) {     // 如果右边位置住了人，幸福感+20
                            mov[s][cur] += 20;
                        }
                    }
                }
            }
        }

        // 动态规划
        for(int r = 1; r <= n; ++r) {              // 枚举1～n行
            for(int i = 0; i <= introvertsCount; ++i) {      // 枚举内向的人的个数
                for(int e = 0; e <= extrovertsCount; ++e) {      // 枚举外向的人的个数
                    for(int s = 0; s < lim; ++s) {            // 枚举上一行（第r - 1行）的状态s
                        if(dp[r - 1][i][e][s] == -1) {        
                            continue;
                        }
                        for(int cur = 0; cur < lim; ++cur) {     // 枚举当前行的状态cur
                            int deltaIn = movIn[s][cur], deltaEx = movEx[s][cur], delta = mov[s][cur];      // deltaIn, deltaEx, delta表示上一行的状态s到这一行的状态cur引起的内向的人数、外向的人数、幸福感的变化
                            if(i + deltaIn <= introvertsCount && e + deltaEx <= extrovertsCount) {          // 如果内向的人数和外向的人数的个数分别不超过introvertsCount和extrovertsCount，则更新最大幸福感
                                dp[r][i + deltaIn][e + deltaEx][cur] = max(dp[r][i + deltaIn][e + deltaEx][cur], dp[r - 1][i][e][s] + delta);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;                  // 我们要求出最后一行（第n行）的最大幸福感，就是最终的答案
        for(int i = 0; i <= introvertsCount; ++i) {            // 枚举内向的人的个数、外向的人的个数、以及第n行的人员分布状态
            for(int e = 0; e <= extrovertsCount; ++e) {
                for(int s = 0; s < lim; ++s) {
                    ans = max(ans, dp[n][i][e][s]);
                }
            }
        }
        return ans;
    }
};
```