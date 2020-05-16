/*
开两个数组，用来记录两个字符串的每个字母。
对两个数组排序之后逐个进行比较，当发现某位的两个字母不同时，
返回第二个数组的字母（记住是第二个的，不能是第一个，因为第二个字符串的字母才是多出来的！）
如果遍历完第一个数组的长度的字母之后也没发现不同，则返回第二个数组的最后一个字符（因为它才是多出来的字母）。
*/


class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> str1, str2;
        for(auto c : s) {
            str1.push_back(c);
        }
        for(auto c : t) {
            str2.push_back(c);
        }
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        for(int i = 0; i < str1.size(); ++i) {
            if(str1[i] != str2[i]) {
                return str2[i];
            }
        }
        return str2[str2.size() - 1];
    }
};
