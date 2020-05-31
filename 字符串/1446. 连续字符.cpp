/*
思路：
双指针（i,j）
一遍扫描所有元素即可，复杂度O（N）
如果s[j] == s[i],就让j的下标增加，最后j的下标就是第一个和s[i]不等的字符的下标，
当前连续的字符串长度就是j - i，然后可以更新一下 res = max(res, j - i)
最后返回res就好了
*/

class Solution {
public:
    int maxPower(string s) {
        int res = 0;
        for(int i = 0; i < s.size();) {
            int j = i + 1;
            while(j < s.size() && s[j] == s[i]) {
                j++;
            }
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};
