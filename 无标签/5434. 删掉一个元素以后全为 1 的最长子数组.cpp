/*
暴力枚举所有情况即可。
用一个zeroPos记录所有0的位置，然后模拟依次删掉每一个0，用一个新的数组newArray记录删掉当前这个0，剩下的所有元素所组成的数组。
然后遍历这个新数组查看连续1的长度，不断更新最大长度即可。
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> zeroPos;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                zeroPos.push_back(i);
            }
        }
        if(zeroPos.size() == 0) {
            return nums.size() - 1;
        }
        int res = 0;
        for(int i = 0; i < zeroPos.size(); ++i) {
            vector<int> newArray;
            int delPos = zeroPos[i];
            for(int j = 0; j < nums.size(); ++j) {
                if(j == delPos) {
                    continue;
                } else {
                    newArray.push_back(nums[j]);
                }
            }
            
            for(int j = 0; j < newArray.size(); ) {
                if(newArray[j] == 0) {
                    ++j;
                } else {
                    int L = j, R = j + 1;
                    while(R < newArray.size() && newArray[R] == 1) {
                        ++R;
                    }
                    res = max(res, R - L);
                    j = R;
                }
            }
        }
        return res;
    }
};
