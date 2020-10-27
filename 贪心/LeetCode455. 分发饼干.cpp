/*
由于要让尽可能多的孩子满足，因此对于每个孩子，我们肯定是把能让他满足的最小的饼干分给他，这样大的饼干可以留给其他胃口更大的孩子，
才有可能让更多的孩子得到满足。

因此，对孩子和饼干尺寸分别从小到大进行排序，然后从小到大遍历每一个孩子，尝试给他分配最小的饼干，如果不满足就找下一块最小的饼干。
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for(int i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
            if(g[i] <= s[j]) {        
                ++res;
                ++i;  
            }
        }
        return res;
    }
};
