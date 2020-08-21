/*
可以枚举所有的运算符的位置，然后递归算出该运算符左右的表达式所有可能的取值，然后对所有可能的取值进行计算。

首先，我们需要把原字符串input中的所有数字和运算符都放到一个vector<string>里，因为每个数字的长度不确定，所以放到
vector里方便我们进行计算。

然后写一个计算expr某段区间的所有表达式的可能结果（用vector<int>存储）的函数dfs，之后，我们再枚举expr中所有的运算符，
递归算出当前运算符左右两侧所有表达式的取值，得到两个数组left和right，分别表示左右两段所有可能的表达式的值，再从两个
数组中分别取出一个值进行计算（计算是什么取决于当前运算符是什么），把结果压入结果数组res中，遍历完两个数组之后就返回res
数组作为dfs函数的返回值。

最终的答案就是dfs(0, expr.size() - 1)，表示所有可能表达式的取值。
*/

class Solution {
public:
    vector<string> expr;

    vector<int> dfs(int l, int r) {
        if(l == r) {                              //如果当前只有一个数，则结果必然是stoi(expr[l])
            return {stoi(expr[l])};
        }
        vector<int> res;
        for(int i = l + 1; i < r; i += 2) {                  //l和r是数字，l + 1和r - 1就是运算符（因为数字和运算符总是交错出现），所以i += 2还是运算符。 这一步是枚举所有的运算符
            vector<int> left = dfs(l, i - 1);                //left和right分别是当前运算符左右两边的表达式的所有可能的取值
            vector<int> right = dfs(i + 1, r);
            for(auto &lnum : left) {                        //从left和right中取出两个值进行计算，算出所有可能的取值
                for(auto &rnum : right) {
                    if(expr[i] == "+") {
                        res.push_back(lnum + rnum);
                    } else if(expr[i] == "-") {
                        res.push_back(lnum - rnum);
                    } else if(expr[i] == "*") {
                        res.push_back(lnum * rnum);
                    }
                }
            }
        }
        return res;
    }

    vector<int> diffWaysToCompute(string input) {
        for(int i = 0; i < input.size(); ++i) {      
            if(isdigit(input[i])) {                              //如果当前找到了一个数字，因为不确定这个数字的长度，所以用双指针把这个数字找出来
                int j = i;
                while(j < input.size() && isdigit(input[j])) {
                    ++j;
                }
                expr.push_back(input.substr(i, j - i));          //j-i是当前这个数字的长度
                i = j - 1;
            } else {
                expr.push_back(input.substr(i, 1));              //如果input[i]不是数字，那就是运算符了，运算符都只有一位
            }
        }
        return dfs(0, expr.size() - 1);                        //返回字符串所有可能的表达式的取值
    }
};
