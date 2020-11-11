/*
就硬算，直接遍历树，求出所有子树元素和的频率，然后再求出现次数最多的子树元素和。

子树元素和的计算可以递归来求，然后用一个先序遍历把所有的子树元素和存到一个哈希表里，然后要计算出现次数最多的子树元素和，可以把
哈希表中所有元素和以及元素和说对应的出现次数放到一个存放pair<int, int>的vector里，其中第一个关键字是子树元素和，第二个关键字是
这个子树元素和在二叉树中出现的次数。然后让vector根据第二个关键字从大到小排个序。
最后，就可以在vector里找到所有出现次数最多的子树元素和了。
说的比较乱，直接看代码吧。
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
using PII = pair<int, int>;

class Solution {
public:
    vector<int> res;
    unordered_map<int, int> hash;                  // 哈希表，记录所有子树元素和和它们出现的次数
    vector<PII> cntFre;                            // 为了给哈希表按照出现次数排序，需要把它们放到一个vector里，pair中第一个关键字是子树元素和，第二个关键字是这个元素和的出现次数

    int getSum(TreeNode* root) {                  // 递归计算以root为根的子树的元素和
        if(root == NULL) {
            return 0;
        } else if(root -> left == NULL && root -> right == NULL) {
            return root -> val;
        }
        return root -> val + getSum(root -> left) + getSum(root -> right);
    }

    void preOrder(TreeNode* root) {                  // 先序遍历，在哈希表里存放所有子树元素和以及它们的出现次数
        if(root == NULL) {
            return ;
        }
        ++hash[getSum(root)];
        preOrder(root -> left);
        preOrder(root -> right);
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        preOrder(root);
        for(auto &h : hash) {                        // 把哈希表中的元素放到vector中
            cntFre.push_back({h.first, h.second});
        }
        sort(cntFre.begin(), cntFre.end(), [&](PII a, PII b) {            // vector根据子树元素和的出现频率排序
            return a.second > b.second;
        });
        int maxFre = cntFre[0].second;                  // maxFre是出现次数最多的子树元素和的出现次数
        for(int i = 0; i < cntFre.size(); ++i) {          // 把所有出现次数和maxFre相等的子树元素和压入res这个vector中
            if(cntFre[i].second == maxFre) {
                res.push_back(cntFre[i].first);
            }
        }
        return res;
    }
};
