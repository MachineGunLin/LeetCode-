class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols));
        for(int j = 0; j < cols; ++j) {
            heights[0][j] = matrix[0][j] == '1' ? 1 : 0;
        }
        for(int i = 1; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == '0') {
                    heights[i][j] = 0;
                } else {
                    heights[i][j] = 1 + heights[i - 1][j];
                }
            }
        }
        int res = 0;
        for(int i = 0; i < rows; ++i) {
            vector<int> left(cols), right(cols);
            stack<int> stk;
            for(int j = 0; j < cols; ++j) {
                while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]) {
                    stk.pop();
                }
                if(stk.empty()) {
                    left[j] = -1;
                } else {
                    left[j] = stk.top();
                }
                stk.push(j);
            }
            stk = stack<int>();
            for(int j = cols - 1; j >= 0; --j) {
                while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]) {
                    stk.pop();
                }
                if(stk.empty()) {
                    right[j] = cols;
                } else {
                    right[j] = stk.top();
                }
                stk.push(j);
            }
            for(int j = 0; j < cols; ++j) {
                res = max(res, heights[i][j] * (right[j] - left[j] - 1));
            }
        }
        return res;
    }
};
