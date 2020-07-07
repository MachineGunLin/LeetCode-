/*
暴力枚举即可，注意特判k为0的情况。
*/

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) {
            return {};
        }
        vector<int> res;
        set<int> hashTable;
        int currentLength;
        for(int i = 0; i <= k; ++i) {
            int j = k - i;
            currentLength = shorter * i + longer * j;
            if(hashTable.count(currentLength) == 0) {
                res.push_back(currentLength);
                hashTable.insert(currentLength);
            } 
        }
        sort(res.begin(), res.end());
        return res;
    }
};
