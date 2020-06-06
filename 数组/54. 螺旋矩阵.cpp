/*
这题和某道面试题一样：https://github.com/MachineGunLin/LeetCode_Solutions/blob/master/%E6%95%B0%E7%BB%84/%E9%9D%A2%E8%AF%95%E9%A2%9829.%20%E9%A1%BA%E6%97%B6%E9%92%88%E6%89%93%E5%8D%B0%E7%9F%A9%E9%98%B5.cpp
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size(), cols = matrix[0].size();
        int totalNumbers = rows * cols;
        vector<int> res(totalNumbers);
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;
        int x = 0, y = 0;
        for(int i = 0; i < totalNumbers; ++i) {
            res[i] = matrix[x][y];
            visited[x][y] = true;
            int newX = x + directions[directionIndex][0], newY = y + directions[directionIndex][1];
            if(newX < 0 || newX >= rows || newY < 0 || newY >= cols || visited[newX][newY] == true) {
                directionIndex = (directionIndex + 1) % 4;
            }
            x = x + directions[directionIndex][0];
            y = y + directions[directionIndex][1];
        }
        return res;
    }
};
