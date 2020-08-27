/*
先同时遍历两个数组，计算相同位置上相同的字母个数，记为cntA。
在遍历的同时，如果相同位置上两个字母不同，就在一个哈希表unordered_map<char, int>上记录不同的数字（在字符串secret)出现的次数。

然后遍历guess数组，用一个变量cntB记录出现在秘密数字中，但位置不一致的数的个数。
遍历到一个字母，这个字母和secret中对应位置的字母不同且哈希表中该字母出现次数大于0，则cntB++,表示找到了一个出现在秘密数字中，但位置不一致
的数字，然后哈希表中该数字的出现次数减一，表示可用的这个数字少了一个。

最后得到cntA和cntB就是A和B的个数，按照题目的要求返回即可。
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        unordered_map<char, int> frequency;                  // 记录secret中那些 和guess数组中相同位置的元素不同的元素出现的次数
        int cntA = 0;
        for(int i = 0; i < size; ++i) {
            if(secret[i] == guess[i]) {
                ++cntA;
            } else {                                         // 如果对应位置的数字不同，则记录一下有可能成为B的数字的个数
                ++frequency[secret[i]];
            }
        }
        int cntB = 0;
        for(int i = 0; i < size; ++i) {
            if(secret[i] != guess[i]) {
                if(frequency[guess[i]] > 0) {                // 当前位置数字和secret中的数字不相等，且我们知道secret中其他位置有这个数字，则我们找到了一个B
                    ++cntB;
                    --frequency[guess[i]];                   // 可用数字数量减一
                }
            }
        }
        return to_string(cntA) + "A" + to_string(cntB) + "B";
    }
};
