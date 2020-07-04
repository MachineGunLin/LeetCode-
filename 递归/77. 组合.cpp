/*
DFS回溯，从左至右选数，加入一个一维数组oneCombination中，当oneCombination的大小等于k，表示已经选了k个数，
将oneCombination压入结果数组res中。

DFS的函数签名可以写为void DFS(int n, int k, int startPos, vector<int>& oneCombination, vector<vector<int>>& res)
表示从1~n里选k个数，当前组合的起始位置为startPos，当前组合记录在一维数组oneCombination中。
这样，只要当前组合oneCombination的大小小于k，我们就可以继续枚举下一个数：DFS(n, k, i + 1, oneCombination, res)  (1 <= i <= n)
当oneCombination的大小等于k时，表示选出了k个数，将当前组合压入res中，递归会回到上一层，也就是只选好了k-1个数的情况（恢复现场），然后
继续判断第k个数能不能选其他的，再上层的递归同理。

递归结束时就找到了所有的k个数的组合，返回结果数组res即可。

由于我们是startPos是从左往右的，且当前组合选的数都必须比startPos大（我们选出的组合都是升序的），所以避免了重复，是OK的。
*/

class Solution {
vector<vector<int>> res;
vector<int> oneCombination;
public:
    vector<vector<int>> combine(int n, int k) {
        DFS(n, k, 1, oneCombination, res);
        return res;    
    }
    void DFS(int n, int k, int startPos, vector<int>& oneCombination, vector<vector<int>>& res) {
        if(oneCombination.size() == k) {                        //当前组合数量已经为k了，甭递归了，res数组中赶紧压入当前组合
            res.push_back(oneCombination);                      //然后回到上一层递归去，搜索第k个数能否是别的数
            return ;
        }
        for(int i = startPos; i <= n; ++i) {                    //当前组合的数必须都大于等于startPos，好马不吃回头草
            oneCombination.push_back(i);                      
            DFS(n, k, i + 1, oneCombination, res);              //当前组合压入了一个数i,继续看看下一个数能放啥
            oneCombination.pop_back();                          //有push_back()必然有pop_back()，回溯一定是对称的！！！！ 因为要恢复现场
        }
    }
};
