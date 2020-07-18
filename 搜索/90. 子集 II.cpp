/*
DFS枚举所有子集，对于每个数字，假设出现次数是cnt，则枚举这个数字的出现次数0,1, 2,.....cnt，其他数字同理。

所以解空间是指数级的。

要计算所有数字出现的次数，可以直接排序，这样同样的数字都是相邻的。

然后一个for循环枚举每个数的添加次数，假设一个数字的出现次数是cnt，则枚举它的出现次数为0, 1, 2,.....cnt。
之后不要忘了恢复现场。

最后两个for循环咋一看难以理解，画一下函数调用关系就明白了。
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        DFS(nums, 0);            //第二个参数是枚举的位置
        return res;
    }
    void DFS(vector<int>& nums, int u) {
        if(u == nums.size()) {
            res.push_back(path);
            return ;
        }
        int k = u + 1;                  //nums[k]是下一个和nums[u]不相等的数字
        while(k < nums.size() && nums[k] == nums[u]) {
            ++k;
        }
        for(int i = 0; i <= k - u; ++i) {      //k-u是nums[u]出现的次数，从0～k-u枚举nums[u]出现的次数 
            DFS(nums, k);                        
            path.push_back(nums[u]);
        }
        for(int i = 0; i <= k - u; ++i) {      //恢复现场
            path.pop_back();
        }
    }
};
