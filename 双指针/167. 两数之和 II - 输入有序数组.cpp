/*
既然题目都说了数组是升序的，那就双指针分别指向数组开头末尾，然后判断两个指针指向的数是否和target相等，如果和小于target，那么左指针右移，这样就可以让和增加了，如果和大于target，那么让右指针左移，这样就可以让和减小了，一直这样操作直到和等于target或者左右指针相遇。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right= numbers.size() - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) {
                return {left + 1, right + 1};
            } else if(sum > target) {
                --right;
            } else if(sum < target){
                ++left;
            }
        }
        return {-1, -1};
    }
};
