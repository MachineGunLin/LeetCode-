/*
这题和51题没什么区别，只不过51题是记录方案，这里是记录方案数。
*/

class Solution {
int res = 0;
int n;
vector<string> path;
vector<bool> cols, diagram, anti_diagram;
public:
    int totalNQueens(int _n) {
        n = _n;
        path = vector<string>(n, string(n, '.'));
        cols = vector<bool>(n);
        diagram = anti_diagram = vector<bool>(2 * n);
        DFS(0);
        return res;
    }
    void DFS(int curRow) {
        if(curRow == n) {
            ++res;
            return ;
        }
        for(int i = 0; i < n; ++i) {
            if(cols[i] == false && diagram[curRow - i + n] == false && anti_diagram[curRow + i] == false) {
                cols[i] = diagram[curRow - i + n] = anti_diagram[curRow + i] = true;
                path[curRow][i] = 'Q';
                DFS(curRow + 1);
                path[curRow][i] = '.';
                cols[i] = diagram[curRow - i + n] = anti_diagram[curRow + i] = false;
            }
        }
    }
};
