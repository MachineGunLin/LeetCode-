/*
要求出某个数除自身以外的数组的乘积，就要求出这个数前面所有数的乘积和这个数后面的所有数的乘积。

求出这个数前面或者后面所有数的乘积可以用前缀和或者后缀和对数组元素进行连续的乘积得到，但是由于这题限制了我们
只能开一个数组（最后的返回数组），所以前缀和用了数组记录之后，后缀和不能再用数组了。

不过没关系，前缀和已经记录了每个元素之前的所有元素的乘积，我们只要从后往前遍历的时候，用一个额外的变量suffix记录
当前元素之后所有元素的乘积即可，每次更新了res数组之后，suffix *= nums[i],这样就更新了后缀和。

从后往前遍历数组结束之后，res数组的每个位置的结果就是除nums[i]以外的其他所有元素的乘积。
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);                  //res[i]表示nums[0...i-1]的乘积
        res[0] = 1;                             //0之前没有元素，res[0] = 1
        for(int i = 1; i < size; ++i) {            
            res[i] = res[i - 1] * nums[i - 1];      //nums[0...i-1]的乘积就是nums[0...i-2]的乘积再乘上nums[i-1]
        }
        int suffix = 1;                              //变量suffix记录当前元素之后的所有元素的乘积，初始为1
        for(int i = size - 1; i >= 0; --i) {
            res[i] *= suffix;                        //res[i]记录了当前元素之前的所有元素的乘积，suffix记录了当前元素之后的所有元素的乘积，二者相乘，就是除自身元素以外的所有元素的乘积
            suffix *= nums[i];                  //更新suffix
        }
        return res;
    }
};
