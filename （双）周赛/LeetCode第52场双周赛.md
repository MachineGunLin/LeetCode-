# LeetCode第52场双周赛

## 第一题 1859. 将句子排序

题目链接：[1859. 将句子排序](https://leetcode-cn.com/problems/sorting-the-sentence/)

- 将单词切成只含英文字符的单词和数字的一对`pair`**<string, int>**
- 然后根据第二关键字对**pair**排序
- 排序后，把单词加到答案字符串**ans**里就行了

```C++
class Solution {
private:
    using PSI = pair<string, int>;
    vector<PSI> words;
    string ans;
    int n;
    
public:
    string sortSentence(string s) {
        n = s.size();
        int i = 0, j = 0;
        while(j < n) {
            j = i;
            while(j < n && s[j] != ' ') {
                ++j;
            }
            // cout << i << ' ' << j << ' ' << s.substr(i, j - i - 1) << endl;
            words.push_back({s.substr(i, j - i - 1), s[j - 1] - '0'});
            i = j + 1;
        }
        sort(words.begin(), words.end(), [&](PSI a, PSI b) {
            return a.second < b.second;
        });
        for(int i = 0; i < words.size(); ++i) {
            ans += words[i].first;
            if(i != words.size() - 1) {
                ans += ' ';
            }
        }
        return ans;
    }
};
```

## 第二题 1860. 增长的内存泄漏

题目链接：[1860. 增长的内存泄露](https://leetcode-cn.com/problems/incremental-memory-leak/)

- 根据题意直接模拟就可以了

```C++
class Solution {
private:
    vector<int> ans;
    int crashTime;
    
public:
    vector<int> memLeak(int memory1, int memory2) {
        for(crashTime = 1; crashTime <= memory1 || crashTime <= memory2; ++crashTime) {
            if(memory1 >= memory2) {
                memory1 -= crashTime;
            } else {
                memory2 -= crashTime;
            }
        }
        ans.push_back(crashTime);
        ans.push_back(memory1);
        ans.push_back(memory2);
        return ans;
    }
};
```

## 第三题 1861. 旋转盒子

题目链接：[1861. 旋转盒子](https://leetcode-cn.com/problems/rotating-the-box/)

- 先构造原矩阵的旋转矩阵**ans**
- 从“下”往“上”考虑每个格子的元素（因为重力是从上往下的）
- 如果当前格子的元素是“石头”，那么我们就往下一直找“箱子底部”、“石头”或“固定障碍物”
- 然后修改当前格子的元素为“空”，再把这个“石头”放在那个位置上
- 这样从下往上修改之后的**ans**矩阵就是答案

```C++
class Solution {
private:
    int n, m;             // n 和 m 分别是 box 矩阵的长和宽
    vector<vector<char>> ans;    // ans 是 box 矩阵顺时针翻转 90 度之后的矩阵
    
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        n = box.size();
        m = box[0].size();
        ans.resize(m, vector<char>(n, ' '));
        for(int i = 0; i < n; ++i) {        // box 矩阵顺时针翻转 90 度，得到 ans 矩阵
            for(int j = 0; j < m; ++j) {
                ans[j][n - i - 1] = box[i][j];
            }
        }
        for(int i = m - 1; i >= 0; --i) {   // 从下往上考虑 ans 矩阵的每个元素
            for(int j = 0; j < n; ++j) {
                if(ans[i][j] == '#') {      // 如果当前位置是个“石头”，那么它会往下“掉”，直到碰到“箱子底部”、其他“石头”或者“固定障碍物”为止
                    for(int k = i + 1; k < m; ++k) {  
                        while(k < m && ans[k][j] == '.') {   // 如果下面一直是“空”，那么石头会一直往下“掉”
                            ++k;
                        }
                        ans[i][j] = '.';        // 修改当前位置的元素为“空”，石头往下“掉”
                        ans[k - 1][j] = '#';
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
```

## 第四题 1862. 向下取整数对和

题目链接：[1862. 向下取整数对和](https://leetcode-cn.com/problems/sum-of-floored-pairs/)

- 用数组 **hash** 记录某个数在 **nums** 数组的出现次数，即 **hash[i]** 表示数字 **i** 在 **nums** 数组的出现次数
- 数组 **preSum** 记录前缀和，**preSum[i]** 表示 **nums** 数组中小于等于**i**的元素个数
- 对于一个数 **i** ，所有在范围**[ j * i, (j + 1) * i - 1 ]**的数除以它并向下取整的数都是 **j**
- 所以我们可以枚举所有的数**i**（i 从 1 到 1e5)
- 对于每个 **i** ，枚举“倍数” **j** ，因为题目给了数据范围是 **1e5**，所以 **i * j <= 1e5**
- 对于固定的数字 **i** 和“倍数” **j**，我们需要知道在范围**[ j * i, (j + 1) * i - 1 ]**内的数的个数，这个个数可以通过前缀和 **preSum[(j + 1) * i - 1] - preSum[j * i - 1]**得到
- 因为在数组 **nums**中，数字 **i**可能出现不止一次，所以当前枚举的 **i** 和 **j** 对答案的贡献是：**(preSum[(j + 1) * i - 1] - preSum[j * i - 1]) * hash[i]**

```C++
class Solution {
private:
    using LL = long long;
    const int MAXN = 1e5 + 10;
    const int mod = 1e9 + 7;
    int ans;
    vector<int> hash;          // hash[i] 表示 nums 数组中数字 i 的个数
    vector<int> preSum;        // preSum[i] 表示 nums 数组中小于等于 i 的元素个数

public:
    int sumOfFlooredPairs(vector<int>& nums) {
        hash.resize(MAXN, 0);
        preSum.resize(MAXN, 0);
        ans = 0;
        for(int i = 0; i < (int)nums.size(); ++i) {
            ++hash[nums[i]];
        }
        for(int i = 1; i < MAXN; ++i) {
            preSum[i] = preSum[i - 1] + hash[i];       // 计算前缀和数组
        }
        for(int i = 1; i < MAXN; ++i) {                // 从 1 到 1e5，枚举所有的数字，考虑它们对答案 ans 的贡献
            for(int j = 1; j * i < MAXN; ++j) {       // j 是当前的“倍数”
                int l = j * i;                // 在 [j * i, (j + 1) * i - 1] 范围内的数除以 i 向下取整得到的整数都是 j 
                int r = min(MAXN - 1, (j + 1) * i - 1);     // 因为 (j + 1) * i - 1 可能超过 MAXN，所以这里要取个min
                ans = (ans + (LL)(preSum[r] - preSum[l - 1]) * j * (LL)(hash[i])) % mod;   // 对于 hash[i] 个 数字 i, 每一个 i，都会对答案贡献 (preSum[r] - preSum[l - 1]) * j  （因为有preSum[r] - preSum[l - 1]个数除以 i 的结果都是 j） 
            }
        }
        return ans;
    }
};
```

