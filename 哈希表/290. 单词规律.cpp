/*
可以用两个哈希表分别记录pattern到str（即字母到单词）和str到pattern(即单词到字母）的映射。

然后检查两个哈希表中的记录，比如某个字母之前已经映射到某个单词，但存在和这个映射矛盾的映射（字母映射到别的单词），
或者是存在某个矛盾的从单词到字母的映射，就返回false。

否则，遍历完发现不存在矛盾的情况，就返回true。
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        for(int i = 0; i < str.size(); ++i) {                  // 因为str里含有空格，所以我们用双指针先把所有的非空单词拆出来，放到一个vector<string> words里
            while(i < str.size() && str[i] == ' ') {
                ++i;
            }
            int j = i;
            while(j < str.size() && str[j] != ' ') {
                ++j;
            }
            string word = str.substr(i, j - i);
            words.push_back(word);
            i = j;
        }
        if(words.size() != pattern.size()) {                              // 如果pattern中字母数量和str的单词数量不同，就无法匹配
            return false;
        }
        int size = pattern.size();
        unordered_map<char, string> Hash1;                              // Hash1记录pattern中的字母对应str中的单词的映射，Hash2相反
        unordered_map<string, char> Hash2;
        for(int i = 0; i < size; ++i) {
            char p = pattern[i];
            string s = words[i];
            if(Hash1.count(p) != 0 && Hash1[p] != s) {                 // 如果之前字母p已经映射了一个单词，且这个单词和现在字母p对应的单词s不同，则矛盾
                return false;
            } else {
                Hash1[p] = s;
            }
            if(Hash2.count(s) != 0 && Hash2[s] != p) {                // 如果之前单词s已经映射了一个字母，且这个字母和现在单词s对应的字母p不同，则矛盾
                return false;
            } else {
                Hash2[s] = p;
            }
        }
        return true;
    }
};
