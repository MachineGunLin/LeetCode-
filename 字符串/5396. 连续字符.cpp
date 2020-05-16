/*
思路：遍历，用两个整数start，end记录连续字母的最大长度。然后更新结果。
最后返回最大长度。
*/

class Solution {
public:
    int maxPower(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        int res = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            int start = i, end = i + 1, currentLength = 0;
            while(s[start] == s[end]) {
                end++;
            }
            currentLength = end - start;
            res = max(res, currentLength);
        }
        return res;
    }
};
