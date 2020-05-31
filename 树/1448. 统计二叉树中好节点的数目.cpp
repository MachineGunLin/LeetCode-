/*
题目中「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
也就是说，如果从根节点到当前节点之前的所有节点的最大值小于等于X的值，那么X就是一个好节点。
因此dfs可以这样写，如果当前节点值大于之前所有节点中的最大值maxv，那么记录res = 1（当前节点是好节点），
同时要更新maxv,因为经过了一个新的节点，所以maxv = max(maxv, root -> val)
由于我们的dfs是返回以当前节点为根的子树的好节点的个数，所以返回值为 res + dfs(root -> left, maxv) + dfs(root -> right, maxv) 这里左右子树的maxv是更新过的。
最后在goodNodes函数里只需返回dfs(root, INT_MIN)
为什么maxv是INT_MIN？ 因为从根节点开始，要保证maxv小于root的节点值（根节点必然是一个好节点），所以把初始的maxv取到int的最小值INT_MIN。
*/

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* root, int maxv) {
        if(root == NULL) {
            return 0;
        }
        int res = (root -> val >= maxv);
        maxv = max(maxv, root -> val);
        return res + dfs(root -> left, maxv) + dfs(root -> right, maxv);
    }
};
