/*
题目说了是对升序的数组做旋转得到的数组，可以考虑二分。

因为做过旋转了，所以不能直接用二分。

找一下规律，旋转数组原来是升序的，那么最小的元素就是旋转前的第一个元素。

旋转之后，相当于把原来升序数组的前面某些部分放到了数组的后面，那么这个数组就满足，在最小的元素之前的部分数组依旧是升序的，然后最小的元素到数组结尾的部分也是升序的。

最小值的前一个元素一定比它大。所以我们需要找到数组“旋转"的位置。

这个旋转位置可以用二分查找，比如说（当前搜索区间的）前半部分，如果nums[mid] > nums[left],说明前半部分是有序的，旋转位置只能在（当前搜索区间的）后半部分。因此让left = mid + 1;
同理如果nums[right] > nums[mid]，说明当前搜索区间的后半部分有序，寻找前半部分：right = mid - 1;

最后，mid的位置就是最小元素的位置或者最小元素的前一个位置，所以将mid和mid + 1以及mid - 1处的元素进行比较，较小的那个元素，就是最终的答案。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(nums.size() == 1) {                        //如果数组只有一个元素，返回这个元素
            return nums[0];
        }
        int left = 0, right = size - 1;
        if(nums[right] > nums[left]) {                 //nums[right] > nums[left]，说明数组压根就没旋转，第一个元素nums[0]就是最小元素
            return nums[left];
        }
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] > nums[left]) {                            //当前搜索区间前半部分有序，搜索后半部分
                left = mid + 1;
            } else if(nums[mid] < nums[right]) {                    //当前搜索区间后半部分有序，搜索前半部分
                right = mid - 1;
            }
            if(nums[mid] > nums[mid + 1]) {                         //这个if要写在下一个if的前面，否则对于样例[2, 1]，会数组越界。原因是mid是下取整得到的，不信自己模拟一下。
                return nums[mid + 1];
            }
            if(nums[mid] < nums[mid - 1]) {                        //mid是我们找到的旋转位置附近的元素，把它与它后一个以及前一个位置的元素比较，较小的那个元素就是数组的最小元素
                return nums[mid];
            }
        }
        return -1;                                                //默认返回值，实际上用不到
    }
};
