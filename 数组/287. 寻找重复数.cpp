class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        set<int> elements;
        for(auto num : nums) {
            if(elements.count(num) != 0) {
                res = num;
                break;
            }
            elements.insert(num);
        }
        return res;
    }
};
