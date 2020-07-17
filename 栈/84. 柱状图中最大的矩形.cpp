class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> left(size), right(size);
        stack<int> stk;
        for(int i = 0; i < size; ++i) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                left[i] = -1;
            } else {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = size - 1; i >= 0; --i) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                right[i] = size;
            } else {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int res = 0;
        for(int i = 0; i < size; ++i) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};
