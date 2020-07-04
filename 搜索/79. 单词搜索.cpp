/*
又是一道DFS回溯，枚举二维字符数组的所有字符作为起点，判断以这个字符作为起点DFS是否能得到word，可以就返回true，
如果所有起点都不行就返回false。

DFS函数就按照方向进行搜索，上下左右是个方向分别去搜，返回的情况有：
      1. 某方向下一个字符和word的下一个字符不相等，回溯，返回false
      2. 已经搜索到了最后一个位置，返回true

如果某方向下一个字符越界或者已经被访问过了（即已经出现在当前从起点开始到现在的字符串中），则跳过（字符串不能包含相同位置的元素）
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));   //因为字符串中不能包含相同位置的元素，所以需要一个二维布尔数组记录某位置元素是否已经在当前字符串中
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(DFS(board, word, 0, i, j, visited) == true) {      //枚举所有起点，判断以这个字符为起点是否能得到word
                    return true;
                }
            }
        }
        return false;            //所有起点搜索都失败了，说明二维数组中不含有word
    }
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};            //枚举四个方向
    bool DFS(vector<vector<char>>& board, string word, int pos, int x, int y, vector<vector<bool>>& visited) {    //pos是当前匹配到word的第几个字符，x，y是当前要判断和word[pos]是否匹配的board中的第i行第j列字符
        if(board[x][y] != word[pos]) {            //如果当前字符不匹配，回溯
            return false;
        }
        if(pos == word.size() - 1) {              //找到匹配到最后一个字符的字符串，成功！
            return true;
        }
        visited[x][y] = true;                     //要搜索新的方向了，先记录当前位置已经被访问过，以防搜索又往回了（字符串不能包含两个相同位置的字符）
        for(int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];        //新方向，新元素
            if(newX < 0 || newX >= board.size() || newY < 0 || newY >= board[0].size() || visited[newX][newY] == true) {  //如果越界或者已经被访问过，跳过
                continue;
            }
            if(DFS(board, word, pos + 1, newX, newY, visited) == true) {    //当前路径可行，返回true
                return true;
            }
        }
        visited[x][y] = false;                  //DFS回溯要恢复现场
        return false;
    }
};
