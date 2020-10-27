/*
直接对于每个元素，枚举他们为起点是否能构成循环。

另外，由于循环中要求所有步数都是同一个方向（向左或向右），因此额外开一个数组directions记录每一步的方向。
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size() < 2) {
            return false;
        }
        for(int i = 0; i < nums.size(); ++i) {
            vector<bool> visited(nums.size(), false);     // 记录当前循环中是否访问过这个元素
            vector<int> directions;    // 1表示向右，-1表示向左
            int curPos = i;                        // 现在的位置
            int curSteps = 1;                      // 现在的步数
            directions.push_back(nums[curPos] > 0 ? 1 : -1);    // nums[curPos]为正数，则是向右，否则是向左
            while(true) {
                visited[curPos] = true;                 // 当前位置已经被访问过
                int nextPos = (curPos + nums[curPos] + nums.size()) % nums.size();  // nextPos是下一步到达的位置
                if(visited[nextPos]) {                   // 如果nextPos之前到达过
                    if(curSteps > 1 && curSteps <= nums.size()) {     // 且步数大于1，并且步数小于nums数组的大小
                        if(nextPos == i) {                            // 并且nextPos就是起点i
                            if(abs(accumulate(directions.begin(), directions.end(), 0)) == curSteps) {  // 那我们还需要判断是否所有步数都是相同方向，如果是的话，directions数组的和的绝对值就是步数curSteps
                                return true;
                            } else {                        // 如果不是所有步数都是相同方向，那这不符合题意中定义的循环，break，枚举下一个起点
                                break;
                            }
                        } else {                             // 否则，跳到下一个位置，步数加1，同时记录一下这一步的方向
                            curPos = nextPos;
                            ++curSteps;
                            directions.push_back(nums[curPos] > 0 ? 1 : -1);
                        }
                    } else {                              // 如果步数为1或者超过了nums数组的大小，则无法构成循环，其中步数超过nums.size()的情况是出现了一个从起点出发，最终在别处产生死循环的情况
                        break;
                    }
                } else {
                    curPos = nextPos;                        // 跳到下一个位置，继续尝试
                    ++curSteps;
                    directions.push_back(nums[curPos] > 0 ? 1 : -1);
                }
            }
        }
        return false;
    }
};
