/*
思路：
滑动窗口： 找从每一个字符作为开始的、不包含重复字符的最长字串。其中最长的子串就是答案。
假设选择第startIndex个字符作为起始位置，并且得到了不包含重复字符的最长子串的结束位置endIndex，
那么当选择第startIndex + 1个字符作为起始位置时，首先从startIndex + 1到endIndex的字符显然都是不重复的，
并且由于少了第startIndex个字符，可以尝试增加endIndex的下标直到右侧出现重复字符为止。

使用哈希表来判断是否有重复字符
startIndex向右移动的时候，从哈希表中移除一个字符，
endIndex向右移动的时候，从哈希表中添加一个字符。
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashTable;
        int startIndex = 0, endIndex = -1, maxLength = 0;
        for(; startIndex < s.size(); ++startIndex) {
            if(startIndex != 0) {
                hashTable.erase(s[startIndex - 1]);
            }
            while(endIndex + 1 < s.size() && hashTable.count(s[endIndex + 1]) == 0) {
                hashTable.insert(s[endIndex + 1]);
                endIndex++;
            }
            maxLength = max(maxLength, endIndex + 1 -startIndex);
        }
        return maxLength;
    }
};
