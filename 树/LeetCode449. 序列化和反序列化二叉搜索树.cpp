/*
要进行序列化和反序列化，我们需要把树用一个字符串来表示，并且能够根据这个字符串唯一地确定二叉搜索树的形态。
由于二叉搜索树本身存在“中序遍历得到的序列是递增序列”这样的性质，我们就要解决如何解决空节点的表示的问题
这里我们把空节点用"#"来表示，遍历一遍二叉搜索树，把树转化成一个字符串表示起来，这是序列化的过程。
反序列化的时候，再根据序列化得到的字符串恢复二叉搜索树。

这里有个技巧，序列化的时候，字符串是根节点的值 + 一个空格 + 左子树序列化后的字符串 + 一个空格 + 右子树序列化后的字符串。

因此在反序列化的时候，可以使用stringstream自动对空格进行分割，然后最开始得到的字串就是根节点的值，第二段字串是左子树，第三段字串是右子树。
在对左、右子树进行恢复（反序列化）的时候，可以递归的调用decode()方法。
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(root == NULL) {                  // 空节点用"#"表示
           return "#";
       } 
       return to_string(root -> val) + ' ' + serialize(root -> left) + ' ' + serialize(root -> right);    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }

    TreeNode* decode(stringstream &ss) {
        string data;
        ss >> data;
        if(data == "#") {   
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(data));   // stringstream读到的第一段字符串是根节点的值
        root -> left = decode(ss);                 // 递归调用decode()方法对左右子树建树，并将root与左右子树连接起来
        root -> right = decode(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
