# LeetCode236. 二叉树的最近公共祖先

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200821102637276-1022157998.png)

对情况进行分类：

（1）如果root为空，则返回NULL；

（2）如果p和q其中之一为root，则这个节点就是最近公共祖先，返回root；

其他情况下，p和q有可能都在root的左子树、都在root的右子树、或者左右子树各一个；
（3）递归计算lowestCommonAncestor(root -> left, p, q)和lowestCommonAncestor(root -> right, p, q)，在root的
左右子树中分别寻找p，q的公共祖先，如果找不到，返回的结果是NULL。
如果左子树找不到，则返回右子树中的查找结果，右子树找不到就返回左子树的查找结果，都找不到，就是p和q左右各一个，返回root。


```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root) {
            return root;
        }
        TreeNode* L = lowestCommonAncestor(root -> left, p, q);
        TreeNode* R = lowestCommonAncestor(root -> right, p, q);
        if(L == NULL) {
            return R;
        }
        if(R == NULL) {
            return L;
        }
        return root;
    }
};
```