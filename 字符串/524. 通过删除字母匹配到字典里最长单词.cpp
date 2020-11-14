/*
这题和[LeetCode522. 最长特殊序列 II](https://www.cnblogs.com/linrj/p/13972685.html)类似，都是在一个字符串数组中找出最长的一个“特殊序列”。

思路也和522题类似，都是对字符串数组按照长度从大到小排序，枚举的时候也是按照字符串长度从大到小枚举，只不过这题里我们要找到最长的，属于字符串s子序列的字符串。
判断某个字符串是否是另一个字符串的子序列的方法和522题完全相同。
*/

class Solution {
public:
    bool checkSubSeq(string a, string b) {                        // 判断字符串a是否是字符串b的子序列
        for(int i = 0, j = 0; i < a.size(); ++i, ++j) {
            while(j < b.size() && a[i] != b[j]) {
                ++j;
            }
            if(j == b.size()) {                              // 如果b走到最后也没有和a匹配完，那么a不是b的子序列
                return false;
            }
        }
        return true;
    }

    string findLongestWord(string s, vector<string>& d) {
        int n = d.size();
        sort(d.begin(), d.end(), [&](string a, string b) {            // 将字符串数组按照字符串长度从大到小排序
            if(a.size() != b.size()) {
                return a.size() > b.size();
            }
            return a < b;
        });
        for(int i = 0; i < n; ++i) {                                  // 将字符串按照长度从大到小枚举，找到第一个属于字符串s的子序列的字符串
            if(checkSubSeq(d[i], s) == true) {                   
                return d[i];
            }
        }
        return "";
    }
};
