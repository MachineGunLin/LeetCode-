/*
思路：模拟
模拟打印矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，则顺时针旋转，进入下一个方向。
如何判断路径何时结束？ 在结果数组中的元素个数达到和matrix数组元素个数相同时结束。
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size(), cols = matrix[0].size();
        int totalNumbers = rows * cols;     //matrix数组元素的个数，res数组元素个数达到totalNumbers时结束循环，返回res数组
        vector<int> res(totalNumbers);
        vector<vector<bool>> visited(rows, vector<bool>(cols));     //记录matrix数组的某个元素是否访问过
        
        /*
        这个方向数组设置的有讲究，注意模拟的方向是顺时针。
        所以一开始先向右，行不变，列加1 -> {0, 1}
        然后向下，行加1，列不变 -> {1, 0}
        后面同理。
        */
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;     //记录下一个元素和当前元素的方向关系
        int x = 0, y = 0;
        for(int i = 0; i < totalNumbers; ++i) {
            res[i] = matrix[x][y];
            visited[x][y] = true;
            int newX = x + directions[directionIndex][0], newY = y + directions[directionIndex][1];
            if(newX < 0 || newX >= rows || newY < 0 || newY >= cols || visited[newX][newY] == true) {
                directionIndex = (directionIndex + 1) % 4;
            }
            /*
            上面的newX和newY其实只是看看当前的directionIndex是否Ok（未超出边界且未被访问过）
            如果不Ok就更新directionIndex。
            真要更新行列还得看下面两行。
            */
            x = x + directions[directionIndex][0];
            y = y + directions[directionIndex][1];
        }
        return res;
    }
};
