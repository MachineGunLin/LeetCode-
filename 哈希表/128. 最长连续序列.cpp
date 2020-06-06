/*
最容易想到的方法是暴力，枚举每一个数，然后判断这个数的下一个数是否存在，还有再下一个数，
直到找到不存在的数，记录一下连续序列的长度，更新一下res。 很显然枚举每个数，对于每个数再枚举之后的
数，时间复杂度是O(n^2)，超时。
优化：
暴力有很多不必要的枚举，比如枚举x, x + 1, x + 2, , , x + y  随后我们遍历到x + 1的时候，又开始从
x + 1 枚举到 x + y，中间有大量重复的计算，所以我们用一个哈希表来优化，枚举一个数x之前先判断x - 1
是否在哈希表中存在，如果存在，说明之前已经从前面的数枚举过了，因此就不枚举了，跳过。
优化之后，外层循环遍历一遍数组是O(n)，只有当一个数是连续序列的第一个数时才会进入内层循环，
然后在内层循环中继续用哈希表匹配连续序列中的数，数组中的每个数只会进入内层循环一次，所以总的时间复杂度是O(n)
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashTable;
        int res = 0;          //最长连续序列的长度
        for(auto num : nums) {
            hashTable.insert(num);
        }
        for(auto num : hashTable) {
            if(hashTable.count(num - 1) == 0) {   //只有当一个数是连续序列的第一个数时才进入内层循环
                int currentNum = num;   
                int currentLength = 1;
                while(hashTable.count(currentNum + 1) != 0) {
                    currentNum++;
                    currentLength++;
                }
                res = max(res, currentLength);
            }
        }
        return res;
    }
};
