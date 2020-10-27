/*
题目要将字符串根据字符出现的频率排序，那我们就将字符的出现次数做一个哈希，然后直接对原字符串根据字符的出现次数
进行降序排序就好了。
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;            // 对字符的出现次数进行哈希
        for(auto &c : s) {
            ++cnt[c];
        }
        sort(s.begin(), s.end(), [&](char a, char b) {  // 根据字符出现频率对字符串进行降序排序
            if(cnt[a] != cnt[b]) {
                return cnt[a] > cnt[b];
            }
            return a < b;
        });
        return s;
    }
};
