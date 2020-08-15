# LeetCode215. 数组中的第K个最大元素

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200815175156705-1225217800.png)

套一个[快速排序](https://www.cnblogs.com/linrj/p/13474463.html)的模板，然后返回第k大的元素即可。

代码如下：

```
class Solution {
public:
    void quick_sort(vector<int> &nums, int l, int r) {                  //快速排序nums数组的[l ~ r]部分，细节分析看上面的链接
        if(l >= r) {
            return;
        }
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while(i < j) {
            do ++i; while(nums[i] < x);
            do --j; while(nums[j] > x);
            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};
```