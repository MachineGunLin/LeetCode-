/*
如果有A[i] + B[j] + C[k] + D[l] = 0，那么就有C[k] + D[l] = -(A[i] + B[j])。

因此我们可以用两重循环遍历A数组和B数组，同时对A[i] + B[j]的所有可能取值进行哈希。

然后再用两重循环遍历C数组和D数组，看一下之前是否对-(C[k] + D[l])做过哈希，如果存在，
说明我们找到了一个和为0的四元组，更新一下答案。
*/

class Solution {
public:
    unordered_map<int, int> hash; 

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        for(int i = 0; i < n; ++i) {               
            for(int j = 0; j < n; ++j) {
                ++hash[A[i] + B[j]];
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                res += hash[-(C[i] + D[j])];
            }
        }
        return res;
    }
};
