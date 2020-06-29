class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            dp[i][0] = 1;                        //到第0列的所有格子都只有一种路径（向下）
        }
        for(int i = 0; i < n; ++i) {
            dp[0][i] = 1;                        //到第0行的所有格子都只有一种路径（向右）
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];       //到第i行第j列只可能是从第i - 1行第j列或第i行第j - 1列移动一步得到
                                                              //因此到第i行第j列的方案数就是第i - 1行第j列的方案数和第i行第j - 1列的方案数之和      
            }
        }
        return dp[m - 1][n - 1];                  //右下角是第m - 1行第n - 1列
    }
};
