/*
题目说了，峰值元素就是大于相邻左右元素的元素，又说了nums[-1] = nums[n] = -∞，所以我们就寻思着，如果nums[0]比nums[1]大，再加上nums[-1]是负无穷，那么nums[0]不就是一个峰值元素了吗。

如果nums[0]不比nums[1]大，那么我们接着把nums[1]和nums[2]比就好了，如果nums[1]大，也可以认为nums[1]是峰值元素。如果nums[1]不比nums[2]大，就继续往后找。

这种做法时间复杂度是O(n).
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return 0;
    }
};

/*
题目希望我们的解法是O(logn)时间复杂度的。
那就得用二分了。

一般二分都是在一个有序的数组里查找元素用的，这里数组是无序的，但因为我们只需要找任意一个峰值，所以也是可以用二分进行查找的。

题目说了nums[-1] = nums[n] = -∞，再加上这题所有的元素都是不相同的（题目说的），所以一定有个元素，比相邻的元素都大。
就算数组元素是递增的，那么最后一个元素也是峰值元素（因为nums[n] = -∞），递减同理。
所以题目保证了有解。

二分的过程是这样的，每次二分出中点mid，将nums[mid]和nums[mid + 1]进行比较，如果nums[mid] < nums[mid + 1]，那么右半部分肯定有峰值，
因为nums[mid + 1]大于mid，而且nums[n]为负无穷，所以右半部分肯定出现了上升又下降这种情况（即出现峰值），所以我们让left = mid + 1(峰值最小也是nums[mid + 1])。

同理，如果nums[mid] > nums[mid + 1]，那么左半部分区间肯定有峰值，因为nums[mid]大于nums[mid + 1]，且nums[0]是负无穷，所以从mid + 1往左走，肯定出现了先上升后下降这种情况，
所以我们让right = mid。

每次折半查找，最后就找到了峰值元素。
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
