# LeetCode235. 二叉搜索树的最近公共祖先

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200821101419157-166949396.png)

二叉搜索树的性质：（1）root为空；（2）或者root左子树中所有元素都小于root->val，root右子树中所有元素都大于root->val，
且root的左右子树也是二叉搜索树。

所以要找两个节点的最近公共祖先，有三种情况：

（1）p，q都在root的左子树中，则我们到root的左子树去寻找他们的祖先（因为需要找最近的祖先）；

（2）p，q都在root的右子树中，则我们到root的右子树去寻找他们的祖先；

（3）其他情况：可能p，q分别在root的左右子树或者反过来，也有可能p和q其中之一就是root，这些情况下，p和q的最近公共祖先都是root。

代码：

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
        if(p -> val < root -> val && q -> val < root -> val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if(p -> val > root -> val && q -> val > root -> val) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};
```