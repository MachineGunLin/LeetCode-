/*
# 解法一（使用O(mn)空间)

可以开一个额外的二维数组，记录每个位置的元素是否已被访问过。

然后我们遍历原来的二维数组，只要没被访问过且元素为0，那么就将该元素所在的行和列的元素值置为0，
并且将这一行的所有元素都设置为已经访问过，以免之后的遍历碰到被置为0的元素也将那一行那一列的元素置为0.

这里要注意，对于一个为0且未被访问的元素所在的行和列的元素置0的时候，要跳过本来就为0的元素，因为可能之后的遍历
到了其他的本来就为0的元素，由于置了那个元素的状态为访问过，就会跳过这个元素，导致没有将那个元素所在的行和列所在的
元素置0.

代码如下：
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();      
        vector<vector<bool>> visited(rows, vector<bool>(cols));      //记录每个元素是否已被访问过
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(visited[i][j] == false && matrix[i][j] == 0) {      //只有当元素为0且未被访问过时，才修改这一行这一列的元素
                    for(int k = 0; k < rows; ++k) {
                        if(matrix[k][j] != 0) {                  //这个if判断不能少，目的是为了防止将这一列本来就为0的元素置为已经访问过，导致无法将那个本就为0的元素所在的行和列的元素置0， 下面的if语句同理
                            matrix[k][j] = 0;
                            visited[k][j] = true;
                        }
                    }
                    for(int k = 0; k < cols; ++k) {
                        if(matrix[i][k] != 0) {
                            matrix[i][k] = 0;
                            visited[i][k] = true;
                        }
                    }
                }
            }
        }
    }
};


/*
# 解法二（使用O(m + n)空间)

给每一个元素都设置一个访问状态需要开二维数组，有点麻烦。

由于我们只需要把0所在的行和列的元素置为0，所以我们可以这样：遍历一遍数组，如果某个元素为0，
那么我们记录一下这个元素的行号和列号。

最后把所有我们记录过的行和列的元素全部置为0即可。

使用这种方法需要开一个O(n)的数组记录每一行是否有0元素，还要开一个O(m)数组记录每一列是否有0元素。
因此空间开销是O(m + n)。

代码如下：
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> rowHasZero(rows), colHasZero(cols);      //两个数组分别记录每一行和每一列是否有0元素
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0) {                  //如果某个元素为0，记录下它的行号和列号
                    rowHasZero[i] = 1;
                    colHasZero[j] = 1;
                }
            }
        }
        for(int i = 0; i < rows; ++i) {      
            if(rowHasZero[i] == 1) {                     //将存在0元素的行的所有元素都置0
                for(int j = 0; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < cols; ++j) {                  //将存在0元素的列的所有元素都置0
            if(colHasZero[j] == 1) {
                for(int i = 0; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


/*
# 解法三 （使用常数空间）

由于要将0元素所在的行和列所在的所有元素都置为0，我们就需要记录哪些行哪些列含有0元素，但是又不能开数组记录，那怎么办呢？

可以考虑直接用原数组记录，比如解法二里开了一个列大小的数组记录每一行是否有0，又开了一个行大小的数组记录每一列是否有0.

**我们可以直接在第0行和第0列记录!** 比如，如果martix[i][j]为0，那么我们就让martix[i][0]为0，表示第i行含有元素0，之后需要将该行所有元素都改为0.
再让martix[0][j]为0，表示第j列含有元素0，之后需要讲该列所有元素都改为0.

这样我们就不需要额外开数组了，但是又有个问题，这样修改了原来的第0行和第0列的元素，咋办？

问题不大，只能开常数空间，不代表不能开空间，我们额外用两个变量记录第0行和第0列是否有0，如果有，在最后就将第0行（列）的所有元素改为0，
如果没有，那么如果第0行或第0列的元素所在的行（列）没有0，那么他们还是原来的值（没有被修改），如果有，那说明（对第0行/列元素的修改）正好改对了呀，
反正他们最后本来就是0！ 这样就解决了空间的问题，使用常数空间就可以将矩阵置0.

代码如下：
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int firstRowHasZero = 0, firstColHasZero = 0;      //判断第0行和第0列是否有元素0
        for(int i = 0; i < cols; ++i) {
            if(matrix[0][i] == 0) {                        //如果第0行有元素0，修改firstRowHasZero，在程序最后将第0行所有元素都改为0
                firstRowHasZero = 1;
                break;
            }
        }
        for(int i = 0; i < rows; ++i) {
            if(matrix[i][0] == 0) {                        //如果第0列有元素0，修改firstColHasZero，在程序最后将第0列所有元素都改为0
                firstColHasZero = 1;
                break;
            }
        }
        for(int i = 1; i < rows; ++i) {               
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;                 //如果某元素为0，修改martix[i][0]为0，表示第i行的元素最后需要全部改为0
                    break;
                }
            }
        }
        for(int j = 1; j < cols; ++j) {
            for(int i = 0; i < rows; ++i) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;                 //如果某元素为0，修改martix[i][0]为0，表示第j列的元素最后需要全部改为0
                    break;
                }
            }
        }
        for(int i = 1; i < rows; ++i) {
            if(matrix[i][0] == 0) {                  //第i行有0元素，把第i行所有元素都改为0
                for(int j = 1; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < cols; ++j) {
            if(matrix[0][j] == 0) {                  //第j列有0元素，把第j列所有元素都改为0
                for(int i = 1; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstRowHasZero) {
            for(int j = 0; j < cols; ++j) {          //第0行有0元素，把第0行所有元素都改为0
                matrix[0][j] = 0;
            }
        }
        if(firstColHasZero) {
            for(int i = 0; i < rows; ++i) {          //第0列有0元素，把第0列所有元素都改为0
                matrix[i][0] = 0;
            }
        }
    }
};
