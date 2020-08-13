/*
这题和LeetCode208. 实现 Trie (前缀树)一样，都是实现Trie树，
支持字符串的插入和查找，只不过这里的查找需要支持正则表达式，也就是可以用'.'代替任何单词，所以我们需要在查找部分做一些修改，
插入单词部分和208题一样。

对于查找单词，由于需要支持正则表达式，所以在查找单词word的某个位置如果是'.'时，需要对于当前树的所有子树进行搜索，因此我们
需要额外写一个dfs函数对字符串进行查找。

这里就在代码部分重点讲一下dfs函数，其他部分和208题一致，这里就不细讲了。
*/

class WordDictionary {
public:
    struct Node {
        Node* son[26];
        bool is_end;
        Node() {
            for(int i = 0; i < 26; ++i) {
                son[i] = NULL;
            }
            is_end = false;
        }
    }*root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); ++i) {
            int u = word[i] - 'a';
            if(p -> son[u] == NULL) {
                p -> son[u] = new Node();
            }
            p = p -> son[u];
        }
        p -> is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);            //从根节点（空）开始，搜索单词word，第三个参数表示当前已匹配前多少个字母
    }

    bool dfs(Node* p, string &word, int i) {
        if(i == word.size()) {                        //如果所有单词都匹配，即在trie树中存在路径和word相等，则需要判断结尾的is_end标记是否为true
            return p -> is_end;
        }
        if(word[i] != '.') {                         //如果当前字母不是通配符'.'，则不需要枚举所有可能的路径
            int u = word[i] - 'a';
            if(p -> son[u] == NULL) {                //只需要看当前字母是否有word[i]这个儿子就好
                return false;
            }
            p = p -> son[u];                        //如果有这个儿子，继续往下递归搜索，匹配word的剩余部分
            return dfs(p, word, i + 1);
        } else {
            for(int j = 0; j < 26; ++j) {                  //如果当前字母是通配符'.'，则需要递归搜索所有的儿子进行匹配
                if(p -> son[j] != NULL && dfs(p -> son[j], word, i + 1) == true) {      //如果沿着某个子树匹配成功，则返回true
                    return true;
                }
            }
            return false;                                    //所有路径都无法匹配，返回false
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
