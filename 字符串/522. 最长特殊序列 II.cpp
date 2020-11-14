/*
可以将字符串数组按照长度从大到小进行排序，然后从前往后遍历，找到第一个特殊序列，这个特殊序列的长度就是答案，如果遍历完数组，都没有找到特殊序列，这返回-1。

特殊序列的判断方法如下：
（1）如果这个字符串存在和它相同的字符串（排序后这两个字符串是相邻的），则这个字符串不是特殊序列。

（2）从最开始（长度最长的）字符串枚举到这个字符串之前的字符串（也就是枚举所有长度比当前字符串大的字符串），判断当前这个字符串是不是其他字符串的子序列，如果是，则它不是特殊序列；如果不是，则当前这个字符串的长度就是最长特殊序列的长度。
*/

class Solution {
public:
    bool checkSubSeq(string a, string b) {                  // 判断字符串a是否是字符串b的子序列
        for(int i = 0, j = 0; i < a.size(); ++i, ++j) {
            while(j < b.size() && a[i] != b[j]) {      
                ++j;
            }      
            if(j == b.size()) {                  // 如果b走到最后也没有和a匹配完，那么a不是b的子序列
                return false;
            }
        }
        return true;
    }

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [&](string a, string b) {         // 将字符串数组按照字符串长度从大到小排序
            if(a.size() != b.size()) {                  
                return a.size() > b.size();
            }
            return a < b;
        });
        for(int i = 0; i < strs.size(); ++i) {        // 按照字符串长度从大到小枚举所有的字符串
            bool flag = true;                         // flag表示当前字符串是否是一个特殊序列
            if(i + 1 < strs.size() && strs[i] == strs[i + 1]) {     // 如果存在和这个字符串相同的字符串，则这个字符串不是特殊序列
                flag = false;
                continue;
            }
            for(int j = 0; j < i; ++j) {                         // 枚举所有长度比当前字符串大的字符串，判断当前字符串是否是其他字符串的子序列
                if(checkSubSeq(strs[i], strs[j]) == true) {
                    flag = false;
                }
            }
            if(flag == true) {                                  // 找到了一个特殊序列，它的长度就是答案          
                return strs[i].size();                  
            }
        }
        return -1;
    }
};
