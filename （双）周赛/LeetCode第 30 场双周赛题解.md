# LeetCode第 30 场双周赛题解

# 5177. 转变日期格式
![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200713091702147-534382137.png)

思路：按照空格划分出年月日，年已经是数字形式，不需要做处理。月是英文单词的缩写，需要对应到相应的数字。
对于日，只需要把结尾的英文序数词去掉，只留下数字即可。 这里要注意月和日可能是个位数，这种情况下要在前面补一个0.

```
class Solution {
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    string reformatDate(string date) {
        string day, month, year, res;
        int split = 0;                        //用双指针划分出字符串
        while(isdigit(date[split])) {      
            day += date[split];
            ++split;
        }
        if(day.size() < 2) {                  //如果是个位数，在前面补一个0
            day = '0' + day;
        }
        while(date[split] != ' ') {           //指针继续移动，划分下一个字符串（月）
            ++split;
        }
        ++split;
        while(date[split] != ' ') {
            month += date[split];
            ++split;
        }
        for(int i = 0; i < 12; ++i) {         //把月份的单词对应到相应的数字上
            if(months[i] == month) {
                month = to_string(i + 1);
            }
        }
        if(month.size() < 2) {                //如果是个位数，在前面补一个0
            month = '0' + month;
        }
        ++split;
        year = date.substr(split);            //剩下的部分就是年
        //printf("%s-%s-%s", year.c_str(), month.c_str(), day.c_str());
        res = year + '-' + month + '-' + day;
        return res;
    }
};
```
这题划分字符串也可以不用双指针，用**stringstream**可以直接以空格为分隔符划分三个字符串。
代码如下：

```
class Solution {
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    string reformatDate(string date) {
        stringstream ss(date);                  //用一个stringstream划分date
        string day, month, year, temp, res;      //temp表示每一个划分出的字符串
        while(getline(ss, temp, ' ')) {         //使用空格作为分隔符
            if(isdigit(temp[0]) && !isdigit(temp.back())) {    //如果某个划分出的字符串temp第一个字符是数字而最后一个不是，则说明现在划分出的字符串是日
                while(!isdigit(temp.back())) {              //删掉末尾的英文序数词
                    temp.pop_back();
                }
                day = temp;                      
                if(day.size() < 2) {                       //如果是个位数，在前面补个0
                    day = '0' + day;
                }
            } else if(!isdigit(temp[0]) && !isdigit(temp.back())) {     //如果某个字符串第一个字符和末尾都不是数字，说明现在划分出的字符串是月
                for(int i = 0; i < 12; ++i) {             
                    if(months[i] == temp) {
                        month = to_string(i + 1);             //把英文单词转化成对应的数字
                        break;
                    }
                }
                if(month.size() < 2) {                        //如果是个位数，在前面补个0
                    month = '0' + month;
                }
            } else if(isdigit(temp[0]) && isdigit(temp.back())) {      //首末都是数字，说明是年，不作处理
                year = temp;
            }
        }
        res = year + '-' + month + '-' + day;
        return res;
    }
};
```

这题用python做会方便很多：

```
class Solution:
    def reformatDate(self, date: str) -> str:
        day, month, year = date.split(' ')
        Months = {"Jan":"01", "Feb":"02", "Mar":"03", "Apr":"04", "May":"05", "Jun":"06", "Jul":"07", "Aug":"08", "Sep":"09", "Oct":"10", "Nov":"11", "Dec":"12"}
        month = Months[month]
        day = day[:2] if day[1].isdigit() else '0' + str(day[0])
        return '-'.join([year, month, day])
```

# 5445. 子数组和排序后的区间和
![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200713093909485-703790508.png)

这题题意是给定一个数组，求出他的所有子数组的和的可能，再对子数组的和排序组成新数组，
对于新数组中下标从left到right（left和right给定）的数组再进算和并返回。

要计算所有子数组和，最简单的想法是枚举所有子数组的起点和终点，再计算这一段的元素和。
同时枚举起点和终点，再在起点和终点里计算和需要O(n^3)的复杂度。超时。

计算子数组和，常见的方法是用一个前缀和数组来优化时间。
额外用一个数组preSum表示每个元素的前缀和，前缀和就是从数组第一个元素到当前元素的和。
比如preSum[3]就是nums[0] + nums[1] + nums[2] + nums[3]。
这样做的好处就是，我们枚举了起点i和终点j之后，要计算这一段子数组的和不需要逐个相加，
可以直接用**preSum[j] - preSum[i]**得到子数组和，这样时间就压缩到了O(n^2).

代码如下：

```
class Solution {
typedef __int64_t bignum;                        //这题数据很大，我们用__int64_t
bignum mod = 1e9 + 7;                            //返回结果要对1e9 + 7取余
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int size = nums.size();
        vector<bignum> preSum(size);
        preSum[0] = nums[0];
        for(int i = 1; i < size; ++i) {
            preSum[i] = preSum[i - 1] + nums[i];      //对所有元素计算前缀和
        }
        vector<bignum> sums;                       //sums数组保存所有的子数组和
        for(int i = 0; i < size; ++i) {
            sums.push_back(preSum[i]);              //每一个前缀和都是一个子数组和
            for(int j = i + 1; j < size; ++j) {
                sums.push_back(preSum[j] - preSum[i]);     //枚举所有起点和终点，计算子数组的和
            }
        }
        //for(auto x : sums) cout << x << ' ';
        sort(sums.begin(), sums.end());
        bignum res = 0;
        for(int i = left - 1; i <= right - 1; ++i) {
            res += sums[i];          
        }
        return res % mod;
    }
};
```
最后一个for循环也可以这么写:
```
for(int i = left - 1; i <= right - 1; ++i) {
            res += sums[i];
            if(res >= mod) {
                res -= mod;
            }
        }
        return res;
```

# 5446. 三次操作后最大值与最小值的最小差
![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200713095344808-818014856.png)

这是一道智商题，如果能发现规律就很好做。

要求出三次操作后最大值和最小值的差的最小值。
我们就要让三次操作之后最大值和最小值尽可能接近，也就是尽可能让最大值小一点，最小值大一点。

所以三次操作都是对数组的最大值（或者前两个或前三个最大值）或者对数组的最小值（或者前两个或前三个最小值）进行操作。
这一点很好理解，如果对一个中间元素进行操作，则对于最大值和最小值的差并无影响。

由于只有三次操作，且都是对于最小或最大的几个数进行操作，所以一共只有四种情况：

1. **三次操作将最小的三个数改为第四小的数。** 修改最小的三个数，修改后的值一定是改为第四小的数，
因为这样才会让最大值和最小值（原来的第四小的值）的差最小。

2. **两次操作将最小的两个数改为第三小的数，一次操作将最大的数改为第二小的数。** 这也是一种缩小最大值和最小值的差的方法。

3. **一次操作将最小的数改为第二小的数，两次操作将最大的两个数改为第三大的数。**

4. **三次操作将最大的三个数改为第四大的数。**

最终的结果，就是上述四种情况的最小值！

注意，如果一共只有四个数或者更少，直接返回0即可，因为肯定可以让最大值和最小值的差相等。

代码如下：

```
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int size = nums.size();
        if(size <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i = 0; i <= 3; ++i) {            //枚举四种情况
            res = min(res, nums[size - 4 + i] - nums[i]);    //更新修改后的最大值和最小值的差的最小值
        }
        return res;
    }
};
```

# 5447. 石子游戏 IV
![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200713105033095-985042366.png)
![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200713105042811-1700669067.png)

题意是给定石头数量，alice和bob每次都只能拿**平方数**个石头，如果某次操作某人拿走了所有的石头，则另一个玩家输。
典型DP问题: 用一个数组dp表示石头数和alice是否稳赢的关系，比如dp[i]表示有i个石头时alice是否稳赢（是返回true，否返回false）。

1. 显然，当i是0时，alice是输得，因为题目说了没有石头时，无法操作的玩家输。

2. 当i是一个平方数时，aclie稳赢，因为只要alice把石头全部拿走，bob就输了。

3. 对于其他情况，就需要判断从当前石头里拿走所有可以拿的平方数个石头的方案里，对方是否一定输。
只要有一种拿平方数的方案里，对方一定输，就可以返回true，否则，遍历完所有可以拿的方案对方都不输，就返回false。

代码如下：

```
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);                  //dp[i]表示有i个石头时alice是否稳赢
        for(int i = 0; i <= n; ++i) {            //从小到大递推计算dp数组
            for(int j = 1; j * j + i <= n; ++j) {     //枚举可以拿的石头数，j * j是当前拿的石头数
                if(dp[i] == false) {                //如果只有i个石头时必输
                    dp[j * j + i] = true;           //那么有j * j + i个石头的时候就必赢，因为alice可以拿走j * j个石头，这样bob就必输
                }
            }
        }
        return dp[n];         //返回有n个石头时alice是否赢
    }
};
```