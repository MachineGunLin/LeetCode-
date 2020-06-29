/*
这题和62题以及63题类似，只不过dp数组的状态表示变了，这里dp数组不再表示方案数，而是到当前格子的最小路径和。
可以发现：要到达第i行第j列的格子，只有从第i - 1行第j列的格子或第i行第j - 1列的格子加上到第i行第j列的格子需要的代价(grid[i][j])得到，
所以如果要得到**到第i行第j列格子的最小路径和**，我们只需要获取第i - 1行第j列的格子或第i行第j - 1列的格子二者中路径和较小的那个，再加上grid[i][j]即可。
由此我们得到状态转移方程：dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
获得状态转移方程后，还需要对dp数组做初始化，显然第0列某个格子的最小路径和等于从起点开始到当前格子的所有代价(grid)相加得到，
因为要到第0列的格子只有从起点一直向下走这一种走法。同理，到第0行的格子也等于从起点开始到当前格子的所有代价总和。
有了递推边界和状态转移方程之后，我们就可以从边界递推到整个数组，最终返回右下角的格子的最小路径和。
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();                  //获取总行数和总列数
        if(rows == 0 || cols == 0) {                                    //需要特判行数或列数为0的情况，LeetCode特色
            return 0;
        }
        vector<vector<int>> dp(rows, vector<int>(cols));                //dp[i][j]表示到第i行第j列的格子的最小路径和
        dp[0][0] = grid[0][0];
        for(int i = 1; i < rows; ++i) {                                 //初始化边界：第0列的所有格子的最小路径和都是从起点开始到当前格子的代价总和
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < cols; ++i) {                                 //初始化边界：第0行的所有格子的最小路径和都是从起点开始到当前格子的代价综合
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < rows; ++i) {
            for(int j = 1; j < cols; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][cols - 1];                                  
    }
};
