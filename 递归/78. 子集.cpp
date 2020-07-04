/*
方法一（DFS回溯）

求出所有可能的子集，就是要遍历一遍DFS递归树，把所有子集全都压入结果数组中。
*/

class Solution {
vector<vector<int>> res;
vector<int> onePath;                  //onePath是递归树的一条路径（一个子集）
public:      
    vector<vector<int>> subsets(vector<int>& nums) {
        DFS(nums, 0);
        return res;
    }
    void DFS(vector<int>& nums, int depth) {            //depth是当前递归的深度
        res.push_back(onePath);                         //要求所有子集，所以把onePath压入res先
        for(int i = depth; i < nums.size(); ++i) {      //继续往深处搜索
            onePath.push_back(nums[i]);
            DFS(nums, i + 1);                          
            onePath.pop_back();                        //DFS回溯都是对称的，所以要恢复现场
        }
    }
};


/*
方法二（二进制位运算）

对于长度为n的数组，我们可以枚举所有长度为n的二进制串，并与数组元素进行与运算，
二进制串中的0表示子集不选这个数，1表示子集选这个数，
这样就直接枚举了所有的子集。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i = 0; i < 1 << nums.size(); ++i) {            //枚举i从 0 ~ 2的nums.size()-1次方减一
            vector<int> oneSubset;
            for(int j = 0; j < nums.size(); ++j) {              //二进制串的长度是nums.size(),所以我们要逐位看看当前二进制串的各个位是0还是1（表示选还是不选）
                if((i >> j) & 1) {                              //判断i的二进制第j位是否为1，要把i右移j位与1做与运算
                    oneSubset.push_back(nums[j]);               //如果是1，说明选第j个数，子集加上nums[j]
                }
            }
            res.push_back(oneSubset);                        //甭管现在子集是啥，肯定是原来没有的（每个二进制子串都不同），所以把子集加入res数组，安排！
        }
        return res;
    }
};
