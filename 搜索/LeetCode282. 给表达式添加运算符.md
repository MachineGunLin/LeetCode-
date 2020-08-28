# LeetCode282. 给表达式添加运算符

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200828114055000-859556538.png)

对于每个位置的两个数之间，都有四种选择：加、减、乘、不填符号（这样两个数就连在一起构成一个更大的数）。

我们可以构造一个代数结构，使得不管下一个位置的数是什么，这个数后面填什么符号，我们都能记录前面已经计算过的字符串的值。

这个代数结构是a + b × c。 a 是我们前面记录过的字符串表达式的值，b是我们当前搜索到的数，c是b下一个位置的数。

这样，如果c后面的符号是+，则整个表达式的值可以用(a+b×c) + 1 × _ 来维护，a + b × c就是a变量的下一个值，也就是我们当前已经
搜索到的字符串表达式的值，_是剩下的字符串的值。a更新为 a+b×c, b更新为1；
同理，如果c后面的符号是-，则整个表达式的值可以用(a+b×c) + (-1) × _来维护。 a更新为a+b×c, b更新为-1；
如果c后面的符号是×，则整个表达式的值可以用a+(b×c)×_来维护。a还是a，b更新为b×c。
如果c后面不填符号，我们直接更新c为一个更大的数: c = c × 10 + num[i] - '0';表示两个数连起来成为一个数。

我们可以在字符串num的最后一位加上一个'+',这样有一个好处，当我们搜索到倒数第二个位置（加上‘+’之前的最后一个位置）时，我们只要看
a的值是否是target就行了，如果a的值是target，则我们可以存下来当前的方案path(path是一个string类型的变量）。  这是因为如果最后一位是
'+'，则当前的a被更新为a + b * c（上面分析过了），如果遍历完了原num字符串，这时的a就是最终的答案。

代码如下：

```
typedef long long LL;                              // 中间结果可能爆int，需要long long来存
class Solution {
public:
    vector<string> res;
    string path;                                  // path存放当前方案

    void dfs(string& num, int u, int len, LL a, LL b, LL target) {      // u是当前搜索到了字符串num的位置，len是当前方案path的长度
        if(u == num.size()) {                                           // 如果搜索到了num的最后一个位置('+')
            if(a == target) {                                           // 这时a存放的就是当前方案下字符串num的值
                res.push_back(path.substr(0, len - 1));                 // len - 1是因为最后一位是'+'
            }
        } else {
            LL c = 0;                                                   // c是我们当前要搜索的数
            for(int i = u; i < num.size(); ++i) {
                c = c * 10 + num[i] - '0';
                path[len++] = num[i];                                   // 先把这个数加到方案path里
                path[len] = '+';                                        // 搜索'+'的方案
                dfs(num, i + 1, len + 1, a + b * c, 1, target);         // a更新为a + b * c, b更新为1
                if(i + 1 < num.size()) {                                // 如果没到倒数第二位，说明还有插入'-'和'*'的方案
                    path[len] = '-';
                    dfs(num, i + 1, len + 1, a + b * c, -1, target);     // a, b的更新之前已经分析过了
                    path[len] = '*';
                    dfs(num, i + 1, len + 1, a, b * c, target);
                }
                if(num[u] == '0') {                                    // 不能有前导0
                    break;
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        path.resize(100);                                                // 因为搜索的复杂度是指数级的，所以path长度不可能太长
        dfs(num, 0, 0, 0, 1, target);                                    // 最开始a是0，b是1，表示 0 + 1 * (整个num表达式可能的取值)
        return res;
    }
};
```