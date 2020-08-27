/*
将二叉树先序遍历解码为一个序列字符串s，不同的数字之间用逗号分隔，如果遇到空节点，就只在s加上一个","。
如果不是空节点，就先加上当前节点的值，然后再加上逗号。

解码的时候，也是取两个逗号之间的值，如果逗号之间为空，则说明是空节点，否则new一个TreeNode出来，节点的值就是两个逗号之间的
子串的值转为int。
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
    void encode(TreeNode* root, string &s) {
        if(root == NULL) {                                    // 空节点在序列化的时候只加上一个逗号
            s += ",";
            return ;
        }
        s += to_string(root -> val) + ",";                    // 非空节点在序列化的时候先加上节点值再加上逗号
        encode(root -> left, s);                              // 先序遍历序列化二叉树
        encode(root -> right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {                  
        string s;                              
        encode(root, s);                                      // 序列化编码的结果记录在字符串s里
        return s;
    }

    TreeNode* decode(string &s, int &cur) {                   // 从字符串s反序列化二叉树，cur是当前解码的字符在字符串s中的下标，这里注意s和cur必须是引用
        if(s[cur] == ',') {                                   // 如果两个逗号之间什么也没有，说明是空节点
            ++cur;
            return NULL;
        }
        int end = cur;                                        // end记录下一个逗号的位置
        while(end < s.size() && s[end] != ',') {
            ++end;
        }
        TreeNode* root = new TreeNode(stoi(s.substr(cur, end - cur)));     // 两个逗号之间的子串的值转为int就是当前节点的值
        cur = end + 1;                                         // cur从下一个逗号的下一个位置开始解码
        root -> left = decode(s, cur);                         // 先序遍历解码字符串s
        root -> right = decode(s, cur);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int cur = 0;                                          // 从要解码的字符串的第0个字母开始解码
        TreeNode* root = decode(data, cur);                    
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
