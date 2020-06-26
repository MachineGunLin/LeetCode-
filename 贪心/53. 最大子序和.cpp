/*
这题是典型的贪心。
我们用一个变量canReach表示最远能到达的距离，canReach的初始值为0。
遍历数组，当遍历到位置x时，如果x小于等于canReach，说明当前位置可以从起点经过若干步跳跃到达，
因此我们可以用canReach = max(canReach, x + nums[x])更新当前可以到达的最远距离。
如果某一步更新了canReach之后，发现最远可到达的距离已经超过了数组的最后一个位置(canReach大于等于nums.size() - 1)，
说明最后一个位置可达，返回true。
如果数组遍历结束之后，canReach还是小于数组的最后一个位置，说明最后一个位置不可达，返回false。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for(auto num : nums) {
            if(sum >= 0) {
                sum += num;
            } else {
                sum = num;
            }
            res = max(res, sum);
        }
        return res;
    }
};
