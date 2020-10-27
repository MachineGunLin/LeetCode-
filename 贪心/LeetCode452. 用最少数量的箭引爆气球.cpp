/*
贪心，由于一支箭可以取到一个气球的左右端点，因此我们对于每个气球，我们只考虑一维区间的右端点，这样在能射爆当前气球的情况下，有可能能射爆
更多后面的气球。
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b) {   // 对区间的右端点进行排序
            if(a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int lastArrow = points[0][1];              // lastArrow表示目前最后一支箭的位置，初始为第一个气球的右端点
        int res = 1;
        for(int i = 1; i < points.size(); ++i) { 
            if(points[i][0] > lastArrow) {        // 如果当前气球左端点在lastArrow右边，那最少还要再加一支箭
                ++res;
                lastArrow = points[i][1];         // 更新最后一支箭的位置为当前气球的右端点
            }
        }
        return res;
    }
};
