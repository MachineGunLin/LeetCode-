/*
这题题目描述的有点不清楚，题意是给一个字符串，如果有某个子串（长度为10）重复出现了，就记录到一个数组里，最后返回的数组就是重复出现的子串组成的数组。

因为子串长度固定为10，所以遍历一遍就行，每个子串都记录到一个set里，这个set就是判断子串是否重复出现了，如果重复出现了，就记录到数组里。

但是由于子串可能不止出现两次，为了防止在数组里加入多次子串，额外再用一个unordered_map记录这个子串是否已经加入到结果数组中，如果加入到了结果数组中，则record[这个子串]不为0（record是这个unordered_map的名字），所以只有当set中count这个子串不为0（表示子串重复出现）且record[这个子串]为0（表示结果数组中没有加入这个子串）时，才把这个子串加入结果数组中。
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> record;                  //记录子串是否已经加入res中，如果加入了，就为1，否则为0
        set<string> hash;                                   //哈希，判断子串是否重复出现
        int size = s.size();
        for(int i = 0; i + 10 <= size; ++i) {               //遍历字符串，枚举所有长度为10的子串
            string temp = s.substr(i, 10);
            if(hash.count(temp) != 0) {                     //子串重复出现
                if(record[temp] == 0) {                      //且结果数组res中还没有记录这个子串
                    res.push_back(temp);                    //则把这个子串加入到结果数组res中
                }
                ++record[temp];                             //修改子串的出现次数
            } else {
                hash.insert(temp);                           //这个子串第一次出现，加入到set中
            }
        }
        return res;
    }
};
