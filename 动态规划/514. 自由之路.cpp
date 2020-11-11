/*
用dp[i][j]表示将keys的前i + 1个字母（0 ~ i）与ring匹配完成、并且当前ring的第j个字母与12:00对齐所需要的 最小步数。

对于key的第一个字母key[0], 要找到ring中某个字母ring[i]与他相等，才能完成key[0]的匹配，可以扫描一遍ring，如果ring[i]与key[0]相等，
那么dp[0][i]就是min(i, m - i) + 1。其中m是ring的大小，min(i, m - i)表示将ring[i]这个字母沿顺时针或逆时针旋转到与key[0]对齐所需要的最小步数，
最后+1表示按下按钮也需要一步操作。 对于ring中不和key[0]相等的字母，初始化dp数组为无穷大。

用n表示key的大小，m表示ring的大小。
计算dp数组的状态转移，需要枚举key的位置i从1～n-1，同时枚举ring的位置j从0~m-1,
如果key[i] == ring[j],则说明可以通过旋转ring来完成key[i]的匹配，而要匹配key[i],肯定是一件匹配完成了前面的字母，
所以我们枚举与key[i - 1]匹配的ring的字母的位置k，如果dp[i - 1][k]不是无穷大，说明可以通过dp[i - 1][k]转移到dp[i][j],
也就是通过旋转ring，使得匹配了key的前i个字母的状态转移到匹配了key的前i + 1个字母的状态。
而这个转移的过程，需要将ring上一步所在的字母位置k移动到位置j，这一步的最小代价是min(abs(j - k), m - abs(j - k)),也就是顺时针或逆时针将k转到j的较小代价，
因此我们可以得到状态转移方程：dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), m - abs(j - k)) + 1,最后的+1也表示按下按钮所需要的一步操作。
我们最后需要的结果就是 匹配完了key的前n个字母，且ring当前指向12:00方向的字母是哪个都行、但是代价是最小的那个方案
也就是dp[n - 1][i从0到m-1]中的最小值。
*/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = key.size(), m = ring.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));           
        for(int i = 0; i < m; ++i) {
            if(key[0] == ring[i]) {
                dp[0][i] = min(i, m - i) + 1;
            }
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(key[i] == ring[j]) {
                    for(int k = 0; k < m; ++k) {
                        if(dp[i - 1][k] != INT_MAX) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), m - abs(j - k)) + 1);
                        }
                    }
                }
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());            // 匹配完key的前n个字母的最小代价
    }
};
