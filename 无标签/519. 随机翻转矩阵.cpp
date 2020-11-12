/*
因为n_rows和n_cols最大能到10^4，所以不能开二维数组，因为那样空间复杂度回到10^8。

题目说了调用flip和reset的次数加起来不会超过1000次，所以矩阵是比较稀疏的，我们只需要记录所有1的位置即可。
我们可以用一个哈希表记录所有1的位置。为了方便，我们把二维的位置映射到一个int变量，哈希表中只记录这个int变量，
比如，如果位置是第r行第c列，那么我们得到:pos = r * cols + c，其中cols是二维矩阵的列数（即n_cols), pos是将{r, c}映射到一维空间的下标。

随机翻转一个0为1的时候，我们只要找出一个不为1（即哈希表中没记录过的）位置pos = rand() % capacity，将这个位置记录到哈希表中（其中capacity是矩阵的大小，即n_rows * n_cols)，
并且求出这个位置对应的二维矩阵的行号: r = pos / cols, 列号: c = pos % cols，将{r, c}作为filp()函数的返回值即可。

reset()方法只需要将哈希表clear即可，表示当前没有记录矩阵中的任何位置的值为1。
*/

using LL = long long;

class Solution {
public:
    unordered_set<LL> hash;            // 哈希表，记录矩阵中的位置映射到一维空间的下标
    LL rows, cols, capacity;           // 行数、列数、矩阵的大小

    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        capacity = rows * cols;
    }
    
    vector<int> flip() {
        LL r, c, pos;
        do {
            pos = rand() % capacity;            // 随机得到一个pos
        } while(hash.count(pos) != 0);
        hash.insert(pos);
        r = pos / cols;                         // pos对应的二维矩阵中的行号r是pos / cols
        c = pos % cols;                         // pos对应的二维矩阵中的列号c是pos % cols
        return {(int)r, (int)c};
    }
    
    void reset() {
        hash.clear();                           // 清空哈希表
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
