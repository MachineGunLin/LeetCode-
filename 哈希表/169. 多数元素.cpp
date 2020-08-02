//遍历一遍数组，对所有元素的出现次数做哈希。


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int size = nums.size();
        for(int num : nums) {
            ++hash[num];
            if(hash[num] > size / 2) {
                return num;
            }
        }
        return 0;
    }
};
