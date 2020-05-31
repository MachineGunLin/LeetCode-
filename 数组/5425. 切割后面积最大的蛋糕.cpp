/*
发现变量命名好像太长了哈哈哈。
思路还是很简单的，分别找出水平和垂直最长的一段边，然后相乘就好了，
最后需要对1e9+7取余
所以返回值为fmod(horizontalMaxLength * verticalMaxLength, 1e9 + 7)
*/

class Solution {
public:
    double maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int horizontalSize = horizontalCuts.size();
        int verticalSize = verticalCuts.size();
        double horizontalMaxLength = max(horizontalCuts[0], h - horizontalCuts[horizontalSize - 1]);
        double verticalMaxLength = max(verticalCuts[0], w - verticalCuts[verticalSize - 1]);
        for(int i = 0; i < horizontalSize - 1; ++i) {
            double betweenDistance = horizontalCuts[i + 1] - horizontalCuts[i];
            horizontalMaxLength = max(horizontalMaxLength, betweenDistance);
        }
        for(int i = 0; i < verticalSize - 1; ++i) {
            double betweenDistance = verticalCuts[i + 1] - verticalCuts[i];
            verticalMaxLength = max(verticalMaxLength, betweenDistance);
        }
        return fmod(horizontalMaxLength * verticalMaxLength, 1e9 + 7);
    }
};


/*
简洁版：简化了变量命名，并且返回值是int类型。
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        //直接把0，h压入hc数组中，同理把0，w压入vc数组
        hc.push_back(0), hc.push_back(h);
        vc.push_back(0), vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int x = 0, y = 0;
        for(int i = 1; i < hc.size(); ++i) {
            x = max(x, hc[i] - hc[i - 1]);      //遍历结束后x就是水平的边之间的最大距离
        }
        for(int i = 1; i < vc.size(); ++i) {
            y = max(y, vc[i] - vc[i - 1]);      //遍历结束后y就是垂直的边之间的最大距离
        }
        return (long long) x * y % 1000000007;  //注意这里 x * y不能加括号变成 (x * y)，会爆int
    }
};
