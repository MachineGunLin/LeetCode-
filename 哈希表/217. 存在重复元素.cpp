/*
开一个set，利用set去重的特性。
把数组所有元素都插入set中，然后比较set的size和数组size是否相同即可。
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto num : nums) {
            s.insert(num);
        }
        if(s.size() != nums.size()) {
            return true;
        }
        return false;
    }
};
