/*
因为字符串可以按照字典序比较大小，所以可以自己写一个排序规则cmp，然后对数组中的所有整数转换成字符串之后再按照自己定义的规则排序。

排序之后，再将所有字符串连接起来，就是它们能够组成的最大整数。

注意特殊情况的判断，如果数组全是0，我们不想要输出"00000...00000"这种情况，只要输出一个0就好了，所以特判一下，排序之后数组第一个元素如果是0，直接return "0";就好了。
*/

class Solution {
public:
    static bool cmp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);      //自定义排序规则，相加字典序大的方案优先
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0) {                  //特判
            return "0";
        }
        string res;
        for(int i = 0; i < nums.size(); ++i) {            //把所有字符串连接起来就好了
            res += to_string(nums[i]);
        }
        return res;
    }
};
