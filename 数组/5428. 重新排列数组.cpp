/*
开两个数组oddArray和evenArray分别存放奇数位的元素（原数组前半部分的元素）和偶数位的元素（原数组后半部分的元素）。
再分别压入结果数组res中。
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n);
        vector<int> oddArray(nums.begin(), nums.begin() + n);
        vector<int> evenArray(nums.begin() + n, nums.end());
        int oddIndex = 0, evenIndex = 0;
        for(int i = 0; i < 2 * n; ++i) {
            if(i % 2 == 0) {
                res[i] = oddArray[oddIndex++];
            } else {
                res[i] = evenArray[evenIndex++];
            }
        }
        return res;
    }
};

/*
优化：无需oddArray和evenArray,只需要i和j分别记录前半部分元素的下标和后半部分元素的下标。
一个for循环分别压入结果数组res中。
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int i = 0, j = n;
        while(i < n) {
            res.push_back(nums[i++]);
            res.push_back(nums[j++]);
        }
        return res;
    }
};

/*
更简洁的做法:不需要j只需要i记录下标即可。
i从0 ~ n - 1，也就是前半部分，那么i + n就从n ~ 2n - 1（后半部分）
分别压入res数组即可。
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};
