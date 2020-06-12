/*
最自然的解法肯定是暴力三重循环，但是这必然超时。 由于题目要求结果不包含重复的数组，可以先对数组进行排序。
第一重循环枚举第一个元素的下标first, 从 0 ~ nums.size() - 2;
接下来需要找到 second 和 third, 满足 nums[first] + nums[second] + nums[third] == 0
由于first在第一重循环中固定下来了，所以我们只需要确定second和third, 这就转换成了一个two sum问题。
可以用双指针解法在 O(n) 时间内确定 second 和 third。
左指针 second 用一个for循环从first + 1开始枚举到 nums.size() - 1
右指针 third 在这个for循环里用一个while循环判断。
因为数组是升序的，所以三数之和大于0时就third--
不大于0时就跳出while循环判断三数之和是否为0，若为0就将 {nums[first], nums[second], nums[third]}压入结果数组。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int first = 0; first < nums.size() - 2; ++first) {
            if(first > 0 && nums[first] == nums[first - 1]) {           //题目要求答案没有重复的三元组
                continue;
            }
            int third = nums.size() - 1;                    //这个third如果定义在下面的for循环里就会超时
            for(int second = first + 1; second < nums.size() - 1; ++second) {
                if(second > first + 1 && nums[second] == nums[second - 1]) {      //题目要求答案没有重复的三元组
                    continue;
                }
                while(second < third && nums[first] + nums[second] + nums[third] > 0) {
                    third--;
                }
                if(second == third) {
                    break;
                }
                if(nums[first] + nums[second] + nums[third] == 0) {
                    res.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return res;
    }
};




/*
上面的写法还可以进一步优化，在内层的for循环外面记录一个 target =  0 - nums[first]，
然后在内层for循环内就完全变成了一个two sum问题， while循环和if循环的判断条件分别变为
while(nums[second] + nums[third] > target) 和 if(nums[second] + nums[third] == target)
这样子会更快一点。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int first = 0; first < nums.size() - 2; ++first) {
            if(first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = nums.size() - 1;
            int target = 0 - nums[first];
            for(int second = first + 1; second < nums.size() - 1; ++second) {
                if(second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while(second < third && nums[second] + nums[third] > target) {
                    third--;
                }
                if(second == third) {
                    break;
                }
                if(nums[second] + nums[third] == target) {
                    res.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return res;
    }
};
