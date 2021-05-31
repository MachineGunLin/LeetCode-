# LeetCode第243场周赛

## 第一题 1880. 检查某单词是否等于两单词之和

题目链接：[1880. 检查某单词是否等于两单词之和](https://leetcode-cn.com/problems/check-if-word-equals-summation-of-two-words/)

- 逐位计算单词之和即可

```C++
class Solution {
public:
    int count(string s) {
        int ans = 0;
        for(const auto& c: s) {
            ans = ans * 10 + c - 'a';
        }
        return ans;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return count(firstWord) + count(secondWord) == count(targetWord);
    }
};
```

## 第二题 1881. 插入后的最大值

题目链接：[1881. 插入后的最大值](https://leetcode-cn.com/problems/maximum-value-after-insertion/)

- 如果`n`是正数，则从左往右找到第一个比`x`小的数，把`x`插入到这个数的左边
- 如果`n`是负数，则从左往右找到第一个比`x`大的数，把`x`插入到这个数的右边

```C++
class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0] != '-') {
            int i = 0;
            while(i < n.size() && n[i] - '0' >= x) {
                ++i;
            }
            if(i == n.size()) {
                return n + to_string(x);
            } else {
                return n.substr(0, i) + to_string(x) + n.substr(i);
            }
        } else {
            int i = 1;
            while(i < n.size() && n[i] - '0' <= x) {
                ++i;
            }
            if(i == n.size()) {
                return n + to_string(x);
            } else {
                return n.substr(0, i) + to_string(x) + n.substr(i);
            }
        }
    }
};
```

## 第三题 1882. 使用服务器处理任务

题目链接：[1882. 使用服务器处理任务](https://leetcode-cn.com/problems/process-tasks-using-servers/)

- 根据题目的规则，我们把服务器分为“空闲的服务器”`idle servers`和“忙碌的服务器”`busy servers`
- 每次一个新的任务到来，都会选择一个“最适合当前任务”的服务器来运行任务
- 新任务到来时：
  - 如果当前有空闲的服务器，则在空闲的服务器里选择权重最小的服务器运行，如果权重都一样，则选择下标最小的服务器
  - 如果没有空闲的服务器，则会等待忙碌的服务器里第一个运行完任务（变为空闲）的服务器去运行任务；如果多个服务器同时变为空闲，则按照空闲的服务器的排序规则进行选择
- 根据这个思想，很容易想到用两个优先级队列去维护**空闲的服务器**`is`和**忙碌的服务器**`bs`，两个优先级队列有不同的排序规则
- 初始时，所有的服务器都是空闲的服务器
- 因为需要记录忙碌的服务器的完成时间，因此我们构建的服务器结构体包含`时间`、`权重`、`下标`三个数据成员
- 对于每个任务，都会从“空闲的服务器”里选择“最合适”的服务器运行任务，这时就把这个服务器从`is`弹出，加入到`bs`
- 如果对于当前任务，没有空闲的服务器，那么就会等忙碌的服务器中出现空闲的服务器，然后再运行任务

```C++
class Solution {
private:
    int n, m;
    vector<int> ans;
    
    struct server {
        int time, weight, index;
        server(int t, int w, int i) {
            time = t;
            weight = w;
            index = i;
        }
    };
    
public:
    struct busyServer {                                    // “忙碌的服务器”的优先队列的排序规则
        bool operator() (server a, server b) {
            if(a.time != b.time) {                         
                return a.time > b.time;
            }
            if(a.weight != b.weight) {
                return a.weight > b.weight;
            }
            return a.index > b.index;
        }
    };
    
    struct idleServer {                                   // “空闲的服务器”的优先队列的排序规则
        bool operator() (server a, server b) {
            if(a.weight != b.weight) {
                return a.weight > b.weight;
            }
            return a.index > b.index;
        }
    };
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        n = servers.size();
        m = tasks.size();
        priority_queue<server, vector<server>, busyServer> bs;
        priority_queue<server, vector<server>, idleServer> is;
        for(int i = 0; i < n; ++i) {
            is.push(server(0, servers[i], i));
        }
        for(int i = 0; i < m; ++i) {
            while(!bs.empty() && bs.top().time <= i) {         // 当前是第 i 秒，忙碌的服务器的优先队列中可能有服务器已经运行完成了，需要弹出堆
                is.push(bs.top());
                bs.pop();
            }
            if(!is.empty()) {                      // 如果有空闲的服务器，则在 is 堆里选择服务器运行，并把服务器加入到 bs 中
                auto t = is.top();
                is.pop();
                ans.push_back(t.index);
                bs.push(server(i + tasks[i], t.weight, t.index));
            } else {                  // 如果没有空闲的服务器，则等待忙碌的服务器中最先运行完成的服务器，在最先完成的服务器中选择服务器运行任务
                auto t = bs.top();
                bs.pop();
                ans.push_back(t.index);
                bs.push(server(t.time + tasks[i], t.weight, t.index));
            }
        }
        return ans;
    }
};
```

## 第四题 5775. 准时抵达会议现场的最小跳过休息次数

题目链接：[5775. 准时抵达会议现场的最小跳过休息次数](https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time/)

- `dp[i][j]`表示经过了前`i`段道路（`i`从`1`开始）、跳过`j`次的最短用时。考虑到精度问题，这里数组是二维的`double`数组
- 考虑状态转移，对于`dp[i][j]`：
  - 如果**跳过**当前道路`dist[i - 1]`，则有：`dp[i][j] = dp[i - 1][j - 1] + dist[i - 1] / speed`
  - 如果**不跳过**当前道路`dist[i - 1]`，则有：`dp[i][j] = ceil(dp[i - 1][j] + dist[i - 1] / speed)`
- 边界情况：
  - 当`j = 0`时，表示我们不跳过任何道路，则`dp[i][j]`无法由任何“跳过道路”的状态转移得到
  - 当`j = i`时，表示我们跳过了所有道路，则`dp[i][j]`无法由任何“不跳过道路”的状态转移得到
  - 跳过次数`j`应该小于道路数`i`
- 最终答案：
  - 对于所有的小于等于`hoursBefore`的`dp[n][i]`（该状态表示通过了所有道路，跳过`i`次的最短用时），我们找到最小的那个`i`，作为结果返回即可
  - 如果在`0 ~ n`的范围内没有找到满足条件的`i`，那么返回`-1`
- 其他细节：
  - 考虑到精度问题，`向上取整操作ceil()`有可能会得到错误答案，常见的做法是减去一个误差值`eps`之后再向上取整
- 参考资料：[官方题解](https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time/solution/minimum-skips-to-arrive-at-meeting-on-ti-dp7v/)

```C++
class Solution {
private:
    const double INF = 1e10;
    const double eps = 1e-8;
    int n;
    vector<vector<double>> dp;
    
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        n = dist.size();
        dp.resize(n + 1, vector<double>(n + 1, INF));
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= i; ++j) {
                dp[i][j] = min(dp[i][j], ceil(dp[i - 1][j] + (double)dist[i - 1] / speed - eps));
                if(0 < j) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (double)dist[i - 1] / speed);
                }
            }
        }
        for(int i = 0; i <= n; ++i) {
            if(dp[n][i] <= hoursBefore) {
                return i;
            }
        }
        return -1;
    }
};
```

