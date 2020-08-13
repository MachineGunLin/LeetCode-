/*
方法一

可以直接用一个数组trie存放所有插入的字符串，然后insert和startsWith操作只需要遍历trie数组，逐个判断即可。
*/

class Trie {
public:
    vector<string> trie;
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        for(const auto &s : trie) {
            if(s == word) {
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int size = prefix.size();
        for(const auto &s : trie) {
            if(s.size() >= size && s.substr(0, size) == prefix) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
方法二

方法一并不是严格的trie树。

我们可以用一个结构体存放trie树的每个节点，每个节点最多可能有a~z共26个孩子，为了方便，我们都用整数表示；另外每个节点还需要记录它们是否是一个单词的结尾，
可以用一个布尔变量is_end表示。

插入的时候，从根节点（空）开始，看当前节点对应的孩子是否和现在这个字母匹配，如果匹配，就继续往下走，如果不匹配，就插入一个字母，实际上，这就是trie树。

搜索的时候同理，如果当前节点对应的孩子和现在查询的字母相同，就继续往下走，否则返回false，如果最后存在一条路径，从根节点到某个节点上的字母组合成了查询的字符串，
还需要看看结尾的字母的is_end变量是否为true，只有当路径存在且路径最后一个字母的is_end变量为true时表示搜索成功。

startsWith和搜索类似，只不过我们只需要找到路径即可，即使路径最后一个节点的is_end变量不为true也没关系，只要存在路径，就说明有单词是以字符串prefix开头的，返回true。
*/

class Trie {
public:
    struct Node {
        Node* son[26];            //节点最多有26个孩子
        bool is_end;              //如果节点是某个单词的结尾，标记一下
    }*root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;                             //p表示我们当前是在哪个节点，最开始在根节点（空）
        for(int i = 0; i < word.size(); ++i) {      //从根节点开始逐层往下搜索
            int u = word[i] - 'a';
            if(p -> son[u] == NULL) {              //如果某节点不存在，则新建一个节点
                p -> son[u] = new Node();
            }
            p = p -> son[u];                        //继续往下走
        }
        p -> is_end = true;                         //标记一下这是一个单词的结尾
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); ++i) {
            int u = word[i] - 'a';
            if(p -> son[u] == NULL) {
                return false;                        //如果没找到，返回false
            }
            p = p -> son[u];
        }
        return p -> is_end;                          //找到一条路径上的单词和word相同，还要看一下is_end变量是否为true，因为这可能是某个单词的前缀
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {                  //startsWith和search类似，唯一不同就是只要路径存在就返回true
        Node* p = root;
        for(int i = 0; i < prefix.size(); ++i) {
            int u = prefix[i] - 'a';
            if(p -> son[u] == NULL) {
                return false;
            }
            p = p -> son[u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 
