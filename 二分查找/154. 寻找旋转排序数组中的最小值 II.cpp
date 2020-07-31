/*
经过旋转后的数组，满足这样一个性质，最小值右边的元素，都大于等于最小值（因为这题有重复元素，所以有可能等于），最小值左边的元素，都大于等于最小值。

所以每一次二分，我们可以与当前区间的最左边或最右边进行比较，确定最小值的位置。

这里我们每次将区间中点的值nums[mid]与区间右端点nums[right]进行比较。

1. 如果nums[mid] < nums[right]，这说明区间右半部分是升序的，那么最小值肯定不在这部分，最小值最大只能是nums[mid],所以让right = mid;

2. 如果nums[mid] < nums[right]，这说明区间右半部分不是升序的，说明数组的旋转位置就在右半部分，最小值肯定在mid + 1 ~ right这部分，所以让left = mid + 1;

3. 如果nums[mid] == nums[right]，这有几种情况，一种数组全都是相同元素，一种是在mid和right之间先上升后下降，后者mid和right之间先下降后上升，不管怎样，我们还需要在这个区间内继续寻找元素，
只不过现在不能直接折半了，而只能让right -= 1（或--right），也就是删去一个重复元素，继续判断nums[mid]和nums[right]（这里的right是刚才那个right的前一个位置）的大小关系。

因为第三种情况最坏情况下每次只能去掉一个元素，所以这题最坏情况下的时间复杂度是O(n)。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[right]) {
                right = mid;
            } else if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                --right;
            }
        }
        return nums[left];            //这里nums[left]和nums[right]都可以
    }
};
