/*
先把区间按照左端点排序，这样排完序之后的列表中的可以合并的区间就都是连续的了。
将列表中第一个区间（最左的区间）加入到结果数组res中，并按顺序依次考虑之后的每个区间：

如果当前区间的左端点大于res数组末尾区间的右端点，则当前区间去前面的区间不重合，直接将这个区间加入res数组中；
否则，表示当前区间与res数组的末尾区间重合，更新res末尾区间为右端点和当前区间右端点二者中的较大值。
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if(res.size() == 0 || res.back()[1] < L) {
                res.push_back({L, R});
            } else {
                res.back()[1] = max(res.back()[1], R);
            }
        }
        return res;
    }
};
