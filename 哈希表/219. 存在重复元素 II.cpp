/*
用一个哈希表记录每个元素的下标（只记录最新的！）
具体做法：
遍历一遍数组，判断元素是否在哈希表中记录过，如果没记录过，
那就记录下；
如果发现之前记录过了，就把当前下标和之前下标做对比，看绝对值差是否小于等于K，
如果小于等于K就返回true，不小于的话就用当前下标覆盖哈希表中当前元素的下标。
遍历结束之后还不为true就返回false咯。
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> getIndex;
        for(int i = 0; i < nums.size(); ++i) {
            if(getIndex.count(nums[i]) == 0) {
                getIndex[nums[i]] = i;
            } else {
                if(abs(i - getIndex[nums[i]]) <= k) {
                    return true;
                } else {
                    getIndex[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
