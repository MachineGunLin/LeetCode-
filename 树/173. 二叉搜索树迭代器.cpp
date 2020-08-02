/*
要实现二叉搜索树的迭代器，判断当前元素是否有下一个元素和知道下一个元素是多少？
好办，二叉搜索树的中序遍历序列不是升序的嘛，那我们就可以对二叉搜索树中序遍历一遍记录到一个全局变量数组里面，然后要判断是否有下一个元素和下一个元素是多少就很简单了。
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
class BSTIterator {
public:
    vector<int> nodes;            //中序遍历，把每一个节点的值记录在nodes数组里
    int cur;                      //当前遍历到的是元素在nodes数组中的下标
    int size;                     //二叉搜索数的节点个数

    void inOrderTraversal(TreeNode* root) {            //中序遍历二叉搜索数，把节点的值记录在nodes数组中
        if(root == NULL) {
            return;
        }
        inOrderTraversal(root -> left);
        nodes.push_back(root -> val);
        inOrderTraversal(root -> right);
    }

    BSTIterator(TreeNode* root) {            //构造函数里进行中序遍历，初始化cur和size
        inOrderTraversal(root);          
        cur = 0;
        size = nodes.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return nodes[cur++];                  //二叉搜索数中的下一个节点值就是nodes中下一个位置的元素，要更新cur访问下一个位置
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur + 1 <= size;              //只要cur不是size - 1（nodes数组的最后一个元素），那么他就有next
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
