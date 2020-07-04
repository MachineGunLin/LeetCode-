/*
这道题是要我们在一个二维数组里搜索某个元素target，找到了返回true,没找到返回false。

这个二维数组性质是，每一行都是升序的，且每一行的最后一个元素小于下一行的第一个元素。

都说升序和查找了，显然应该想到二分。

这题我最开始先按行二分，确定target(如果在数组里）所在的行，再对这一行做二分确定target所在的列，但是TLE了，就不贴出代码了。

可以发现，这个二维数组，如果我们能把它变成一维数组，不就是一个升序的一维数组了吗？那这题不就是裸的二分了吗？

可以开一个额外的一维数组顺序存放二维数组的元素，但没必要。

可以直接将二维数组的下标映射到一维数组里，这样就比较节省空间。

如果行数为rows, 列数为cols，对于某个元素martix[i][j]，它在一维数组的下标就是i * cols + j。
这是二维数组下标转换为一维数组下标。

但是我们二分要对一维数组二分呀，所以我们需要把一维数组的下标转换为二维数组，显然一维数组的下标范围是0 ~ rows * cols - 1。

从上面二维数组转一维数组下标我们可以发现，行号实际上是一维数组下标除以列数，列号实际上是一维数组下标对列数取余。

也就是说，一维数组中下标为x的元素，在二维数组中行号为 x / cols, 列号为 x % cols（这个很好理解，cols是一行的大小嘛）

然后就是对这个一维数组做二分啦。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {            //空数组特判，LC特色
            return false;
        }
        int rows = matrix.size(), cols = matrix[0].size();            
        int left = 0, right = rows * cols - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid / cols][mid % cols] == target) {            //找到了，返回true
                return true;
            } else if(matrix[mid / cols][mid % cols] > target) {
                right = mid - 1;
            } else if(matrix[mid / cols][mid % cols] < target) {
                left = mid + 1;
            }
        }
        return false;                  //搜遍了也没找到，返回false
    }
};
