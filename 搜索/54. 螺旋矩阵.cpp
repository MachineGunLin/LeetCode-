/*
题意是，输入一个二维数组，从数组左上角开始，沿着顺时针慢慢地“遍历”每一个元素且每一个元素只遍历一次，
在一个新的一维数组中记录遍历的顺序，最终的返回值就是这个数组。
思路：可以考虑用方向来模拟“一个指针的移动”，指针指向的元素如果合法（不越界且未被访问过），就将这个元素压入结果数组。
这里的核心是“移动指针”，移动指针要注意两点：

1. 移动的方向是顺时针：即先往右，再往下，再往左，再往上，再往右。。。。
这里可以用两个方向数组作辅助，比如原来的坐标是(x, y)，那么“往右”可以表示为 newX = x, newY = y + 1.
也就是说，每次移动一个方向，只是改变x和y的其中一个值，且改变的值可以枚举。
所以可以用dx表示x的改变: int dx[4] = {0, 1, 0, -1};
用dy表示y的改变: int dy[4] = {1, 0, -1, 0};
再用一个整数变量direction表示“当前的方向”，比如direction为0时，dx[direction] = 0, dy[direction] = 1,
newX = x + dx[direction] = x, newY = y + dy[direction] = y + 1 表示“当前方向向右”

2. 移动的时候要注意避免“撞墙”，撞墙有两种情况：一种是(newX, newY)越界，一种是(newX, newY)已经访问过了。碰到撞墙，就需要
再更新一下(newX, newY）（通过改变方向）。
由于要记录是否访问过，所以要额外再开一个二维数组记录每个位置的元素是否访问过。
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> res(rows * cols);
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int x = 0, y = 0, direction = 0, cnt = 0; cnt < rows * cols; ++cnt) {
            res[cnt] = matrix[x][y];
            visited[x][y] = true;
            int newX = x + dx[direction], newY = y + dy[direction];
            if(newX < 0 || newX >= rows || newY < 0 || newY >= cols || visited[newX][newY] == true) {
                direction = (direction + 1) % 4;
                newX = x + dx[direction], newY = y + dy[direction];
            }
            x = newX, y = newY;
        }
        return res;
    }
};
