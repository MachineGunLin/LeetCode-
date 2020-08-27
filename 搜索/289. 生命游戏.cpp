/*
可以直接额外写一个函数count计算周围每个格子周围八个位置中活细胞的数目，再根据当前位置是活细胞还是死细胞以及周围
活细胞的数目更新当前位置board的值。
*/

class Solution {
public:
    vector<vector<int>> g;
    int rows, cols;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int count(int x, int y) {                                    // 计算格子(x, y)周围八个位置的活细胞数目
        int res = 0;
        for(int i = 0; i < 8; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && g[newX][newY] == 1) {
                ++res;
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        g = board;
        rows = g.size(), cols = g[0].size();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int neighbours = count(i, j);                        // neighbours是(i, j)周围八个位置的活细胞的数目
                if(g[i][j] == 1) {                        
                    if(neighbours < 2 || neighbours > 3) {           // 如果当前位置是活细胞，且周围活细胞的数目小于2或者大于3，则下次更新成死细胞
                        board[i][j] = 0;
                    } 
                } else {                                             // 如果当前格子是死细胞，且周围活细胞数目恰好为3，则下次更新成活细胞
                    if(neighbours == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
