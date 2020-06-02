/*
这道题最容易想到的解法是 等差数列求和公式:
*/

class Solution {
public:
    int sumNums(int n) {
        return (n + 1) * n / 2;
    }
};

/*
或者用递归:
*/

class Solution {
public:
    int sumNums(int n) {
        return n == 0 ? 0 : n + sumNums(n - 1);
    }
};

/*
但是这题题目限制了不可以用乘除法、循环还有条件判断(A ? B : C)，所以我们考虑用 && 把递归改造一下。
*/

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));   //这个本质上还是递归啦
        return n;
    }
};
