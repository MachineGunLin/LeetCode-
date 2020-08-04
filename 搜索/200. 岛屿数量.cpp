/*
非常经典的搜索问题。遍历数组，从每一个1开始深度优先搜索当前位置联通的位置是否都是1（也就是与它联通的陆地），用一个额外的布尔数组visited记录每一个位置的元素是否已经访问过，每个遍历过的位置visited都标记为true。
*/

class Solution {
public:
    vector<vector<bool>> visited;
    int res = 0, rows, cols;
    int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};            //这两个数组表示x，y的方向
    
    void DFS(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i) {                            //搜索四个方向
            int newX = x + dx[i], newY = y + dy[i];            //计算下一个位置
            if(newX < 0 || newX >= rows || newY < 0 || newY >= cols || grid[newX][newY] != '1' || visited[newX][newY]) {      //如果新位置越界或者不为1或者已经访问过了，就跳过
                continue;
            }
            DFS(newX, newY, visited, grid);                   //否则从下一个位置继续寻找联通的1
        }
    }

    int numIslands(vector<vector<char>>& grid) {     
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        rows = grid.size(), cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == '1' && !visited[i][j]) {      //找到了一个没有被访问过的陆地起点，更新答案数，从这个位置开始DFS，寻找所有与他联通的1，并更新visited数组
                    ++res;
                    DFS(i, j, visited, grid);
                }
            }
        }
        return res;
    }
};
