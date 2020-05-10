/*
思路：如果某个节点为true，就向上一路同化父节点也为true。
最终的结果就是每两个连接（父、子节点都为true)的线的个数 * 2后的和。
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int res = 0;
        for(int i = edges.size() - 1; i >= 0; i--) {
            if(hasApple[edges[i][1]] == true) {     //如果某个节点为true
                hasApple[edges[i][0]] = true;       //则向上同化父节点也为true
            }
        }
        for(int i = 0; i < edges.size(); i++) {
            if(hasApple[edges[i][1]] == true) {     //最终结果即为所有父子节点均为true的线的个数 * 2
                res += 2;
            }
        }
        return res;
    }
};
