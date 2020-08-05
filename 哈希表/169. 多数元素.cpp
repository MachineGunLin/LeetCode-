//遍历一遍数组，对所有元素的出现次数做哈希。


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int size = nums.size();
        for(int num : nums) {
            ++hash[num];
            if(hash[num] > size / 2) {
                return num;
            }
        }
        return 0;
    }
};




/*
上面的做法时间和空间复杂度都是O(n)，这道题还有一个时间复杂度O(n),空间复杂度O(1)的做法。

我们可以开两个变量，curNum记录当前的（“我们认为的”）出现次数最多的数，cnt记录这个数出现的次数（其实也不完全是这样，继续往下看）

当cnt大于0的时候，假设我们当前遍历到了一个数nums[i],我们看看nums[i]和curNums是否相同，如果相同，很好，cnt加一，继续看下一个数。

如果nums[i]和cnt不同，说明出现了一个和（“我们认为的”）出现次数最多的数不同的数，那我们把cnt减一，表示这两个数抵消了。
然后看一下，这个减一操作之后，cnt是否为0，如果为0，说明我们认为的出现次数最多的数curNum被抵消了，（到目前为止）最起码有和他一样多的数。

抵消之后，我们再暂且认为现在这个新的数nums[i]是出现次数最多的数，所以把他的值赋给curNum, 然后cnt = 1（因为他现在出现了一次嘛）。

就一直这样下去，遍历一遍数组之后，curNum记录的就是数组中出现次数超过数组长度一半的数。

这个算法咋看起来不可思议，为什么这是正确的呢？
我们可以用反证法，假设数组遍历之后curNum的值不是数组中出现次数超过数组长度一半的数，那说明，真正的在数组中出现次数最多的数（出现次数超过数组长度一半的数）
被抵消为0了（因为只有被抵消为0的时候才会改变curNum的值），也就说明了数组里最起码有一半的数不同，和题意矛盾，故这个算法是正确的。
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        int curNum = nums[0], cnt = 1;            //最开始我们认为第0个数是出现次数最多的
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == curNum) {               //如果当前的数就是我们认为的最大的数，good，next！
                ++cnt;
            } else {
                --cnt;                           //找到了不同的数，抵消一下
                if(cnt == 0) {                   //抵消为0，我们就该反思一下，maybe我们之前找的数并不是出现次数最大的
                    curNum = nums[i];
                    cnt = 1;
                }
            }
        }
        return curNum;
    }
};
