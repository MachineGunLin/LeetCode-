/*
题目是要遍历1 ~ n，如果当前遍历到的数字在target数组中存在，则在res数组中压入"Push"；
如果不存在，则在res数组中压入"Push",再压入"Pop"。
考虑到target数组第一个数字可能不是1，所以用一个diff记录target[0]和1的差值，在res数组中
压入diff个"Push"和"Pop"先，之后再遍历target[0]到n，判断数字是否在target数组中出现，若出现，
就在res数组压入"Push"，然后继续判断下一个数字，否则压入"Push"和"Pop"。
要注意到target数组遍历完之后就可以退出了。
*/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int diff = target[0] - 1;
        while(diff--) {
            res.push_back("Push");
            res.push_back("Pop");
        }
        int firstTarget = target[0];
        int currentIndex = 0;
        for(int i = firstTarget; i <= n; i++) {
            if(i == target[currentIndex]) {
                res.push_back("Push");
                currentIndex++;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
            if(currentIndex == target.size()) {
                break;
            }
        }
        return res;
    }
};
