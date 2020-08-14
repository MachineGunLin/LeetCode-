# LeetCode212. 单词搜索 II

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200814145742158-1472217967.png)

这题是[LeetCode79. 单词搜索](https://www.cnblogs.com/linrj/p/13237466.html)的进阶版，第79题是在二维的char数组里搜索单个单词，
这题需要在二维char数组里搜索一组单词。

理论上只需要对遍历单词数组，逐个套用79的dfs方法即可，不过这题题目要求了需要用Trie树做优化。

所以，我们最开始可以把单词列表里的所有单词都插入到一个Trie树中，然后对单词做搜索的时候，除了检查下一个位置的字母不越界且未使用过（题目要求
同一个单元格内的字母不允许被重复使用）以外，还需要检查下一个位置的字母是否是当前字母在trie树的孩子。

通过这个额外的Trie树的剪枝，可以减小搜索空间。

有几点需要注意:
（1）Trie树存储每个单词的时候，需要在每个单词的结尾字母打一个标记，我们用一个整数变量id来确定当前字母是第id个字母（id从0开始）的结尾。
id就是单词在words列表中的顺序。  我们在dfs的时候，成功搜索到单词的标志就是最终的指针指向的字母的id不为-1（构造函数中对id初始赋值为-1）。

（2）我们可能会在char数组中多次搜索到同样的单词，所以需要额外用一个哈希表unordered_set来对dfs函数搜索到的单词的id进行记录。

（3）我们把二维char数组board记录到一个全局二维char变量g中，并用全局变量rows和cols记录二维数组的行数和列数，这样dfs函数可以少传几个参数。

代码如下：

```
class Solution {
public:
    vector<vector<char>> g;                  //记录二维字符数组
    int rows, cols, dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};          //g的行数、列数、dfs的四个方向
    unordered_set<int> ids;                   //用来去重

    struct Node {                                 //Trie树的节点
        int id;
        Node *son[26];
        Node() {
            id = -1;                              
            for(int i = 0; i < 26; ++i) {
                son[i] = NULL;
            }
        }
    }*root;

    void insert(string &word, int id) {                  //在Trie树中插入单词，并在结尾记录id
        Node *p = root;
        for(int i = 0; i < word.size(); ++i) {
            int u = word[i] - 'a';
            if(p -> son[u] == NULL) {
                p -> son[u] = new Node();
            }
            p = p -> son[u];
        }
        p -> id = id;
    }

    void dfs(int x, int y, Node *p) {
        if(p -> id != -1) {                        //搜索成功一个单词，在哈希表ids中记录id
            ids.insert(p -> id);
        }
        char temp = g[x][y];                        //题目要求同一个单元格内的字母在一个单词中不允许被重复使用，所以我们先记录下这个位置的字符，然后暂时将他修改为'.'，表示不可用，dfs之后再恢复现场
        g[x][y] = '.';
        for(int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < rows && newY >= 0 && newY < cols                  //如果下一个位置不越界
            && g[newX][newY] != '.' && p -> son[g[newX][newY] - 'a'] != NULL) {      //且下一个位置未被使用过(g[newX][newY] != '.')，且在Trie树中下一个字母是当前字母的孩子
                dfs(newX, newY, p -> son[g[newX][newY] - 'a']);                      //继续搜索
            }
        }
        g[x][y] = temp;                              //恢复现场，把这个位置的字母从'.'恢复到它本来的样子
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        g = board;
        rows = g.size(), cols = g[0].size();
        root = new Node();
        for(int i = 0; i < words.size(); ++i) {                  //把所有单词插入到一个Trie树中
            insert(words[i], i);
        }
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int u = g[i][j] - 'a';                         
                if(root -> son[u] != NULL) {                   //如果当前字母是Trie树根节点的孩子，说明从当前位置搜索单词可能有戏
                    dfs(i, j, root -> son[u]);                  //开始搜索
                }
            }
        }
        for(auto id : ids) {                                   //去重之后，我们就知道哪些单词搜索到了，把这些搜索到的单词加入到结果数组res中
            res.push_back(words[id]);
        }
        return res;
    }
};
```