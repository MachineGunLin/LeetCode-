/*
从后往前遍历数组，同时维护一个单调递减的栈，因为是单调栈，所以栈顶元素是目前的最大值（可以认为是132中的3），
同时我们要记录第二大的值，也就是单调栈中栈顶元素的下一个元素，我们用变量secondGreatest来记录这个值。
secondGreatest可以认为是132中的2。
同时我们继续往前遍历，（1）如果当前遍历到的数nums[i]小于secondGreatest，那他必然也小于栈顶元素，因为secondGreatest
小于栈顶元素，换句话说，我们找到了一个132模式，因此返回true。（2）否则的话，需要比较一下当前元素与栈顶元素的关系，如果
当前元素大于栈顶元素，说明栈顶元素现在不是最大元素了（即132中的3），但这个“栈顶元素”还是有成为132中的2的潜质的，而这个nums[i]
有可能是132中的3，所以我们记录secondGreatest，然后将nums[i]压入栈中。
和之前一样，我们将这个栈顶元素视为132中的3，secondGreatest为132中的2。
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int secondGreatest = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(nums[i] < secondGreatest) {
                return true;
            }
            while(!stk.empty() && nums[i] > stk.top()) {
                secondGreatest = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
