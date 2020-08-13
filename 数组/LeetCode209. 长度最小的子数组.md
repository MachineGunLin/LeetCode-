#  LeetCode209. 长度最小的子数组

![](https://img2020.cnblogs.com/blog/2078361/202006/2078361-20200628191334755-1390152491.png)
# 方法一
暴力枚举所有可能的子数组，也就是枚举子数组的所有开始下标和结束下标，计算子数组的和，如果子数组的和小于等于s，就更新最小长度。
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) {                  //数组为空的情况需要特判
            return 0;
        }
        int res = INT_MAX;                      //最终的返回结果，初始化为一个较大的数
        for(int i = 0; i < nums.size(); ++i) {  //枚举子数组的起始下标
            int sum = 0;                        //子数组的和
            for(int j = i; j < nums.size(); ++j) {     //枚举子数组的结束下标
                sum += nums[j];
                if(sum >= s) {
                    res = min(res, j -i + 1);          //如果子数组的和小于等于s，就更新res
                    break;                      //不要忘了加 break !!!
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
# 方法二
同样是枚举子数组的起始下标，我们考虑优化子数组结束下标的搜索空间，如果能用二分找到（满足子数组的和大于等于s）子数组结束下标的位置，相比于方法一就会更快，
二分查找要求数组是单调的，由于题目保证每一个元素都是正的，所以我们考虑用一个sums数组记录前缀和，也就是说，sums[i]表示nums[0] ~ nums[i - 1]的元素总和，
这样，问题就转化为对于每一个起始下标i，通过二分查找寻找一个大于等于i的**最小下标bound**,使得**sums[bound] - sums[i - 1] >= s**，sums[bound] - sums[i - 1]就是子数组的和。找到了bound之后，我们就更新子数组的最小长度（此时子数组的长度是bound - (i - 1))。
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int size = nums.size();
        vector<int> sums(size + 1, 0);            //这里sums的大小为size + 1,是因为我们要让sums[0]为0,方便下一句的for循环对suns做初始化
        for(int i = 1; i <= size; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int res = INT_MAX;
        for(int i = 1; i <= size; ++i) {
            int target = s + sums[i - 1];         //target 为 s + sums[i - 1]，也就是说如果某个数bound的前缀和sums >= target,那么以i为起始下标，到bound的子数组的和就大于等于sum
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if(bound != sums.end()) {            //如果bound不越界，就更新子数组的最小长度
                res = min(res, static_cast<int>((bound - sums.begin()) - (i - 1)));   
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
# 方法三
考虑用双指针，两个指针start和end分别表示子数组的开始和结束下标，变量sum表示以start开头，以end结尾的子数组的和。start, end, sum的初始值都为0.
先将nums[end]加入sum中，如果sum < s，就继续增加end（当然同时也把nums[end]加入sum)直到sum >= s，此时不增加end，而是更新子数组的最小长度（此时长度为end - start + 1),然后不断增加start（并更新子数组的最小长度）直到sum < s,然后再继续增加end，直到end超过了数组最大下标。
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int start = 0, end = 0, sum = 0, res = INT_MAX;
        while(end < nums.size()) {
            sum += nums[end];
            while(sum >= s) {
                res = min(res, end - start + 1);
                sum -= nums[start];
                ++start;
            }
            ++end;
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
# 复杂度分析
1. 暴力方法中枚举起始下标需要O(n),内层循环枚举结束下标又需要O(n),因此时间复杂度是O(n)；由于无需额外的辅助数组，因此空间复杂度是O(1);
2. 前缀和 + 二分查找同样需要O(n)来枚举起始下标，但这里对于子数组的结束下标使用了二分查找进行优化，查找的复杂度是O(logn)，因此总的时间复杂度是O(nlogn)；由于需要一个额外数组sums存放前缀和，因此空间复杂度是O(n);
3. 双指针方法中，左右指针start和end都只会向右移动，并且对于每个起始下标，无需从头开始枚举结束下标，因此时间复杂度是O(n);双指针方法也无需额外的辅助数组，空间复杂度为O(1).