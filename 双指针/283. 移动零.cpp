/*
双指针，用两个指针zero和nonZero分别找到一个为0和一个不为0的数，且如果不为0的数在为0的数后面，则交换这两个数。
如果在0的前面，则不用交换，zero指针不动，nonZero从zero指针的下一个位置开始寻找一个不为0的数，与zero指针交换。

重复这个过程，直到两个指针其中之一越界。
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, nonZero = 0, size = nums.size();
        while(zero < size && nonZero < size) {
            while(zero < size && nums[zero] != 0) {
                ++zero;
            }
            if(zero == size) {
                return ;
            }
            while(nonZero < size && nums[nonZero] == 0) {
                ++nonZero;
            }
            if(nonZero == size) {
                return ;
            }
            if(zero < nonZero) {
                swap(nums[zero], nums[nonZero]);
            } else {
                nonZero = zero + 1;
            }
        }
    }
};
