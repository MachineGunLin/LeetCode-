/*
动态规划，用dp[i][j]表示第i行第j列的格子到终点所需的最小初始值，这题如果从左上往右下递推，就需要同时记录从起点到当前位置的路径和以及从起点到当前位置所需要的最小初始值，比较麻烦。

因此我们可以从右下往左上递推，这样递推到每个格子只需要维护当前位置到起点（这里的起点是右下角了）的最小初始值，最后的dp[0][0]（表示从左上角到右下角的最小初始值）就是答案。

对于每一个dp[i][j],它都只与dp[i][j + 1], dp[i + 1][j], dungeon[i][j]有关，如果min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j]是正数，那么dp[i][j]就是min(dp[i][j + 1], dp[i + 1][j]) -dungeon[i][j]，表示从(i, j)出发只要有不少于min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j]个生命值，骑士就能到达右下角。

为什么是min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j] ? 这个表达式就是说减去dungeon[i][j]的血量，骑士可以到达一个只需要最小的血量min(dp[i][j +1], dp[i + 1][j])就可以到达右下角的格子。

不过min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j]可能是个负数或者0，根据题意，生命值大于0，最少也得是1，所以状态转移方程是dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1);

对于边界状态，最后一行以及最后一列，因为dp[i][j + 1]和dp[i + 1][j]不都存在，所以开数组的时候多开一行一列，把格子最后一行的下一行以及格子最后一列的下一列的dp[i][j]赋值为INT_MAX, 因为状态转移方程是对于下一行和下一列的dp值取min，所以可以对它们赋值成INT_MAX。

另外，对于右下角的格子，考虑到它的dp[i][j + 1], dp[i + 1][j]如果都是INT_MAX，且dungeon[i][j]是负数的情况下会产生溢出，因此我们把右下角dp[i][j + 1]和dp[i + 1][j]都赋值为1，表示减去dungeon[i][j]的生命值之后还剩下1格生命值，这样再往左上递推就不会溢出了。
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), cols = dungeon[0].size();                  //行数和列数
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));      //多开一行和一列
        dp[rows - 1][cols] = dp[rows][cols - 1] = 1;                           //右下角的格子的下一行和下一列的格子初始赋值为1，这样就不会溢出
        for(int i = rows - 1; i >= 0; --i) {                                   
            for(int j = cols - 1; j >= 0; --j) {
                dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1);    
              }
        }
        return dp[0][0];
    }
};
