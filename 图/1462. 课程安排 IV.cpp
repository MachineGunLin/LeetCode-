/*
要知道一个课是不是另一个课的先修课。
这就是一个图的最短路径问题，相当于一个点通过某些路径可以到达另一个点。
用Floyd算法更新，如果i是k的先修课，k是j的先修课，那么i也是j的先修课。
也就是if(isPre[i][k] == true && isPre[k][j] == true) {
          isPre[i][j] = true;
      }
然后再遍历queries数组,在结果数组res中压入isPre[query[0]][query[1]]
最后返回res数组就好了。
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<bool>> isPre(n, vector<bool>(n));
        for(auto pre : prerequisites) {
            isPre[pre[0]][pre[1]] = true;
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; j++) {
                    if(isPre[i][k] == true && isPre[k][j] == true) {
                        isPre[i][j] = true;
                    }
                }
            }
        }
        for(auto query : queries) {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};
