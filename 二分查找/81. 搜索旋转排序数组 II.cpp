/*
方法一 先排序后二分

要判断数组里是否存在target，可以先对数组排序，然后直接二分查找。

这样时间复杂度是O(nlogn)。
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            }
        }
        return false;
    }
};


/*
方法二 直接二分

题目说了原数组是经过有序数组旋转得到的，我们考虑直接在旋转后的数组上做二分。

由于旋转之后的数组多半并不是全局有序的，而只是局部有序，所以要加一些额外的判断。

按照二分的套路，我们先判断nums[mid]和target是否相等，如果相等，就不用考虑别的了，直接返回true。
否则，就要在左半部分或右半部分数组寻找target了。

我们的思路是先找左半部分，如果左半部分没找到，再找右半部分，都没找到就返回false。
当然找的过程也是二分查找。

对于左半部分，由于我们不知道这部分数组的单调情况，所以需要先判断第一个元素nums[left]和nums[mid]的关系，

      1. 如果nums[left] < nums[mid],那就说明左半部分数组是升序的，如果nums[left] <= target && target < nums[mid]，
      说明数组中如果存在target，只可能在数组的左半部分，我们就在左半部分二分查找 ->   right = mid - 1;
      如果target的值不在[nums[left], nums[mid])之间，也未必就说明数组中没有target，这时需要去数组的右半部分查找 -> left = mid + 1;
      如果左右部分都没有找到，说明数组中没有target，返回false。

      2. 如果nums[left] > nums[mid],说明右半部分数组是升序的（反证法：如果这时右半部分不是升序的，则数组不可能由一个有序数组旋转得到），
      如果nums[mid] < target && target <= nums[right],说明数组中如果存在target，只可能在数组的右半部分，我们只需要在右半部分二分查找
      target就好了 -> left = mid + 1; 如果target的值不再(nums[mid], nums[right]]之间，不代表数组中就没有target了，还需要去搜索数组的
      左半部分 -> right = mid - 1;
      如果左右部分都没有找到，说明数组中没有target，返回false。

      3. 如果nums[left] == nums[mid]，这时无法判断左半部分的单调情况，需要++left,直到我们确定一个有序的局部才可以二分。这些被“过滤”调的前面部分
      可以不用管，因为他们和nums[mid]相等，如果nums[mid]不等于target，那么它们也不等于target，所以我们只把剩下的左半部分（第一个不等于nums[mid]的
      数当作nums[left]到nums[mid]这部分）当作左半部分做二分查找。
      举个例子：比如数组为[1, 1, 0, 1, 1, 1, 1]，nums[left] == nums[mid]时就一直++start，所以我们过滤掉了开头的两个'1'，剩下的左半部分是[0, 1)，
      然后再判断nums[left]和nums[mid]谁大谁小，继续做二分。
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[left] == nums[mid]) {
                ++left;
                continue;
            }
            if(nums[left] < nums[mid]) {
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
