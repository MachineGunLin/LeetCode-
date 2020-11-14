/*
题目说了N不会超过15，这就是在暗示我们用DFS。

直接DFS出1～N的排列，然后判断一下是否满足条件。

不过这里要剪枝一下，不需要枚举出所有的排列之后逐个判断，对于某个排列的某一位u，如果已经不满足条件了，即不满足u % i == 0 或者 i % u == 0，那么就无需枚举剩下的位。

这题不加这个剪枝貌似会超时。
*/

class Solution {
public:
    int res = 0;
    int n;
    vector<bool> visited;     // 判断某个数字是否已经在当前排列出现过

    void dfs(int u, vector<bool>& visited) {
        if(u == n + 1) {                  // 找到一个满足条件的排列，答案++
            ++res;
            return ;
        }
        for(int i = 1; i <= n; ++i) {
            if(visited[i] == false && ((u % i == 0) || (i % u == 0))) {  // 当前数字没有排列中出现过，且满足题目要求的条件，则尝试在当前位置放上数字i，再继续搜索下一个位置
                visited[i] = true;
                dfs(u + 1, visited);
                visited[i] = false;
            }
        }
    }

    int countArrangement(int N) {
        n = N;
        visited = vector<bool>(n + 1, false);
        dfs(1, visited);
        return res;
    }
};
