/*
这题和第54题类似，都是套一个搜索的模板。
用dx和dy表示方向，方向的顺序是先向右，再向下，再向左，再向上，再向右。。。
如果“撞墙”了就需要改变到下一个方向。“撞墙”的判定就是(newX, newY)越界或者已经被访问过。
“撞墙”就需要改变方向，即更新(newX, newY)。
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int x = 0, y = 0, direction = 0, cnt = 1; cnt <= n * n; ++cnt) {
            res[x][y] = cnt;
            visited[x][y] = true;
            int newX = x + dx[direction], newY = y + dy[direction];
            if(newX < 0 || newX >= n || newY < 0 || newY >= n || visited[newX][newY] == true) {
                direction = (direction + 1) % 4;
                newX = x + dx[direction], newY = y + dy[direction];
            }
            x = newX, y = newY;
        }
        return res;
    }
};
