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
