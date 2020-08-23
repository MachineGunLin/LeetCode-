 # LeetCode第33场双周赛

# 第一题 5479. 千位分隔数

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200823081038207-1963272412.png)

把数字转换成字符串并翻转，然后每三位加一个"."，之后再翻转字符串，就是最终的答案了。

```
class Solution {
public:
    string thousandSeparator(int n) {
        string N = to_string(n);                        
        reverse(N.begin(), N.end());
        int size = N.size();
        string res;
        for(int i = 0; i < size; ++i) {
            res += N[i];
            if(i != 0 && i != size - 1 && (i + 1) % 3 == 0) {      //每三位加一个. 但如果是第一个数字和最后一个数字，就不用加了
                res += ".";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

# 第二题 5480. 可以到达所有点的最少点数目

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200823081345201-1304151032.png)

首先，对于所有入度为0的点，由于没有边可以到达这个点，所以我们是一定要把它们加入到答案中的，
然后，由于题目给的是有向无环图，所以所有点一定都是从一个入度为0的点到达的，所以入度大于0的点，无需加入到
答案中，因为答案中已经有了所有入度为0的点，从某个入度为0的点出发，肯定可以到达这个点。
所以问题就转换为，找出所有入度为0的点。

```
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> inDegrees(n);
        for(auto &edge : edges) {                  // 根据所有边计算入度
            ++inDegrees[edge[1]];
        }
        for(int i = 0; i < n; ++i) {
            if(inDegrees[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
```

# 第三题 5481. 得到目标数组的最少函数调用次数

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200823083745107-420070346.png)
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200823083803341-158600007.png)

我们考虑把nums数组变成全0数组，这个操作是把全0数组变成nums数组的逆向操作，所以操作次数是一样的。

因为+1操作（这里是逆向，所以是减一操作）每次只能对一个数操作，而乘2操作(这里是除二操作）可以对整个数组进行操作，
所以我们考虑尽量多地对数组进行除二操作。因为除二操作总是比减一操作更优。不过除二的时候，要求数组中所有数都是偶数，
所以需要先把数组中的奇数进行减一操作转换成偶数，然后对整个数组进行除二操作。

为什么说除二操作总是比减一操作更优？

比如一个奇数n, (n-1-1-1)/2和(n-1)/2-1值是一样的，但前者进行了四次操作（三次减一操作变成偶数之后才可以进行除2操作），后者只
进行了三次操作（一次减一变成偶数，一次处2，再一次减一），所以，对于一个奇数，一次减一变成偶数之后就进行除2是最优的。

对于一个偶数n，(n-1-1)/2和n/2-1的值也是一样的，前者进行了三次操作，后者进行两次操作。所以说对于偶数，也是尽早做除2才是最优的。

因此我们的思路是这样：遍历数组，如果数组中有奇数，则对于每个奇数都用一个减一操作把他们变为偶数，同时我们要记录一个bool变量modified
表示数组中是否有奇数，如果某个时刻没有奇数。则需要检查（1）当前数组中是否全0（如果全0，则返回操作次数res）；（2）不是全0，说明当前
数组中都是偶数（但不是全0），用一次除2操作把所有数除2，然后继续判断。

由于数据范围最大是10^9，所以30次除2操作之内就可以变成全0.

代码如下：

```
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        while(true) {
            bool modified = false;                  //记录当前数组中是否有奇数，如果有奇数，将他减一修改为偶数
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] % 2 == 1) {
                    ++res;
                    --nums[i];
                    modified = true;
                }
            }
            if(modified == false) {
                if(*max_element(nums.begin(), nums.end()) == 0) {            //如果当前数组全0，退出循环，返回答案
                    break;
                } 
                for(int i = 0; i < nums.size(); ++i) {                  //否则，对整个数组所有元素除2
                    nums[i] /= 2;
                }
                ++res;
            }
        }
        return res;
    }
};
```

# 第四题 5482. 二维网格图中探测环

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200823091327503-1001742730.png)
![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200823091341777-171915502.png)

判断环需要dfs，对于所有格子，沿着和他（值）相同的格子进行深度优先搜索，同时记录格子是否被访问过，如果某个时刻，沿着和相同的
格子搜索的时候找到了一个之前访问过的格子，说明存在环；而如果下一个格子和当前格子（值）相同，但是没访问过，就从下一个格子继续往后
搜素，直到找到了环或者没有和格子的值相同的格子可以继续搜索为止。

遍历所有格子，只要有某个格子满足（从这个格子开始搜索）能找到环，就返回true，否则说明二维网格中不存在环，返回false。

代码如下：

```
class Solution {
public:
    vector<vector<char>> g;                              // 把二维网格grid记录到全局变量g里面，这样dfs可以少传一个参数hh
    vector<vector<bool>> visited;                        // 记录某个格子是否访问过
    int rows, cols;                                       // 网格的行数、列数
    int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};     // 搜索的四个方向

    bool dfs(int x, int y, int lastX, int lastY) {           // x,y表示当前搜索到的格子的坐标，lastX和lastY是上一个格子的坐标
        visited[x][y] = true;                         
        for(int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < rows && newY >= 0 && newY < cols
            && !(newX == lastX && newY == lastY) && g[newX][newY] == g[x][y]) {      // 下一个格子不能和上一个格子坐标相同，且格子内的值相等才能往下搜索
                if(visited[newX][newY] == false) {                  // 如果下一个格子没有访问过
                    if(dfs(newX, newY, x, y) == true) {            // 且从下一个格子开始往下搜索可以找到环
                        return true;                              
                    }
                } else {                                          // 如果下一个格子搜索过了，说明我们找到了一个环
                    return true;
                }
            } 
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        rows = g.size(), cols = g[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(visited[i][j] == false) {                        // 从没搜索过的格子开始搜索
                    if(dfs(i, j, -1, -1) == true) {                 //最开始假设上一个坐标为-1, -1，也就是第一个点不考虑所谓的“上一个格子”
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```