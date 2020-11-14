/*
直接按照题意进行深度优先搜索，只要当前位置不是地雷，且周围还存在方块可以揭露（搜索）时，就继续搜索，否则停止搜索，返回面板（board）。

（1）如果搜到当前位置是地雷，那就修改为'X'。

（2）用一个int变量cnt记录周围8个位置的地雷数量。
      （i）如果cnt不为0，说明周围有地雷，用对应的数字字符更新这个位置。
      （ii）如果cnt为0，说明当前位置是一个空白方块，则从这个空白方块周围八个位置继续往下揭露（搜索）。

当莫得方块可以继续揭露时，返回面板。
*/

class Solution {
public:
    int n, m;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {            // dfs的返回值表示从坐标(x,y)的格子能否继续往下揭露格子
        visited[x][y] = true;
        if(board[x][y] == 'M') {            // 找到一个地雷，更新当前位置为'X'
            board[x][y] = 'X';
            return true;
        }
        int cnt = 0;                        // cnt记录（x，y）周围的地雷数量
        for(int i = 0; i < 8; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == 'M') {
                ++cnt;
            }
        }
        if(cnt > 0) {                        // 如果周围有地雷，这将当前位置修改为地雷数量
            board[x][y] = '0' + cnt;
        } else {
            board[x][y] = 'B';                // 题目说了如果挖出一个空白方块被挖出，则需要递归地揭露与其相邻的方块
            for(int i = 0; i < 8; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] == false && dfs(board, visited, newX, newY) == true) {
                    return true;
                }
            }
        }
        return false;            
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        dfs(board, visited, click[0], click[1]);
        return board;
    }
};
