/*
一顿dfs就行了，dfs参数里传一个string变量path记录从根节点到当前节点的路径的字符串。
然后dfs里面加一些判断，如果是空就return，如果左右子树都为空就现在结果数组res里记录当前的路径path，然后return。
然后在路径path上加下"->"，如果左子树不空就dfs左子树，如果右子树不空就dfs右子树。

搜索完整个二叉树之后res数组中记录的就是答案。
*/

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
    vector<string> res;

    void dfs(TreeNode* root, string path) {
        if(root == NULL) {
            return ;
        }
        path += to_string(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            res.push_back(path);
            return;
        }
        path += "->";
        if(root -> left != NULL) {
            dfs(root -> left, path);
        }
        if(root -> right != NULL) {
            dfs(root -> right, path);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};
