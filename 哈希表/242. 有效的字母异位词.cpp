/*
对字符串中所有字母做哈希，计算字母的出现频率，哈希表unordered_map<char, int> HashS记录字符串s中每个字母的
出现频率，unordered_map<char, int> HashT记录字符串t中每个字母的出现频率，如果两个哈希表相等，说明t是s的有效
字母异位词，否则不是。
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> HashS, HashT;
        for(auto &c : s) {
            ++HashS[c];
        }
        for(auto &c : t) {
            ++HashT[c];
        }
        return HashS == HashT;
    }
};
