/*
既然同一个字符如果要替换，就都得替换成相同的字符，我们可以开哈希表记录某个字符映射成了哪个别的字符，但是由于两个字符不能映射到相同的字符上，如果a映射成o，r也映射成o，那么bar就可以替换成foo了，这是不符合题意的。

我们注意到，如果我们对foo也建立一个哈希表，那么o只能映射成一个字符，foo就不能映射成bar了。

因此我们可以开两个哈希表st和ts分别记录s到t和t到s的字符映射关系，然后我们遍历两个字符串，看一下相同的字符是否都映射到了同样相同的字符上。
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        int size = s.size();
        unordered_map<char, char> st, ts;
        for(int i = 0; i < size; ++i) {
            if(!st.count(s[i])) {            //如果哈希表st中之前没有记录字符s[i]应该映射为哪个字符
                st[s[i]] = t[i];             //那就记录一下s[i]要映射到t[i]
            } else {
                if(st[s[i]] != t[i]) {       //否则，说明这个字符不是第一次出现了，我们把（记录过的）他应该映射成的字母和t[i]对比一下，如果不相等，说明s和t不同构
                    return false;
                }
            }
            if(!ts.count(t[i])) {            //这个if语句和上面同理，记录t到s的字符映射关系
                ts[t[i]] = s[i];
            } else {
                if(ts[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
