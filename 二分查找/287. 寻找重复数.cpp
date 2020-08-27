/*
因为所有数字都在1~n之间，所以我们可以枚举1~n，然后再遍历nums数组看一下是不是有数字出现次数超过1次。
这样时间复杂度是O(n^2)，还可以优化。

考虑这样一种情况，如果每个数字x（1<=x<=n)在数组里出现次数超过1次，则我们遍历数组的时候计算所有小于等于x的
数的个数cnt,cnt必然大于等于x。
而对于所有小于等于x的数，他们都只出现一次（因为题目说了只有一个数重复出现），则对于每个数分别计算nums数组里小于等于他们的数
的个数，这个个数一定和这个数相等，也就是从1到他们自身的数的个数。

所以，我们可以通过二分，对于1~n中的数，分别计算nums数组中小于等于这个数的元素个数，找出第一个，在数组中小于等于这个数的元素的个数
大于自身的数，这个数，就是那个重复出现的数。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        int left = 1, right = n;                  // 从在区间[1, n]内进行二分查找
        while(left < right) {
            int mid = left + right >> 1;
            int cnt = 0;                          // cnt计算nums数组中小于等于mid的元素个数
            for(int i = 0; i < n; ++i) {
                if(nums[i] <= mid) {
                    ++cnt;
                }
            }
            if(cnt > mid) {                       // 如果cnt > mid, 说明重复元素在区间[1, mid]
                right = mid;
            } else {                              // 否则，说明重复元素在区间[mid + 1, n]
                left = mid + 1;
            }
        }
        return left;
    }
};
