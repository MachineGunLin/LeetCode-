/*
思路： arr[i] ^ arr[i + 1] ^ ... ^ arr[j -1] 可以转换为
(arr[0] ^ arr[1] ^ ... ^ arr[i - 1] ) ^ (arr[0] ^ arr[1] ^ ... ^ arr[j - 1])
因为相同的值异或为0，而异或一个0不影响结果。
所以考虑到用数组dp[i] 表示 arr[0] ^ arr[1] ^ ... ^ arr[i]，
最终解法就是 暴力 + 记忆化搜索
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        int dp[size];
        dp[0] = 0;
        for(int i = 1; i < arr.size(); i++) {
            dp[i] = dp[i - 1] ^ arr[i];
        }
        int res = 0;
        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                for(int k = j; k < arr.size(); k++) {
                    if((dp[i] ^ dp[j - 1] ^ arr[i]) == (dp[k] ^ dp[j] ^ arr[j])) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
