class Solution {
public:
    int numTrees(int n) {
        if(n == 1 || n == 2) return n;
        vector<int> nums = {1, 1, 2};
        int index = 3;
        while(index <= n) {
            int temp = 0;
            for(int i = 1; i <= index; i++) {
                temp += (nums[i - 1] * nums[index - i]);
            }
            nums.push_back(temp);
            index++;
        }
        return nums[n];
    }
};
