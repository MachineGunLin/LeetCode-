/*
对于新插入的区间newInterval，原区间列表intervals可以分为三个部分：
1. 左边与newInterval不重合的区间，这些区间直接加入结果数组中；
2. 中间与newInterval重合的区间，我们需要更新newInterval的左右端点，使得左右端点分别为重合部分的最左和最右；
3. 右边与newInterval不重合的区间，这些区间直接加入结果数组中。
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        if(i < intervals.size()) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                ++i;
            }
        }
        res.push_back(newInterval);
        while(i < intervals.size()) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};
