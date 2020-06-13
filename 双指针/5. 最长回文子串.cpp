/*
解法一：动态规划
用二维数组dp[i][j]表示s从第i个位置到第j个位置的子串是否是回文子串，是则为1，否则为0。
枚举子串长度len从0 ～ length - 1 （length是字符串s的长度）
再枚举子串的起始位置i从0 ～ length - len
所以时间复杂度是 O(n ^ 2),由于开了二维数组dp，所以空间复杂度也是 O(n ^ 2)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length));
        string res;
        for(int len = 0; len < length; ++len) {
            for(int i = 0; i < length - len; ++i) {
                int j = i + len;
                if(len == 0) {                      //如果子串长度为0，说明就当前这个字符，dp[i][j] = dp[i][i] = 1
                    dp[i][j] = 1;
                } else if(len == 1) {               //如果子串长度为1，就判断相邻两个字符是否相等即可，相等的话dp[i][j]就是1
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1] == 1);       //状态转移方程，dp[i][j]等于1的前提是dp[i + 1][j - 1]等于1且s[i] == s[j]
                }
                if(dp[i][j] == 1 && len >= res.size()) {          //如果回文子串长度大于等于当前的res
                    res = s.substr(i, j + 1 - i);               //就更新res，这里注意一下substr函数第一个参数是子串的起始位置，第二个参数是子串的长度，不是子串的结束位置！
                }
            }
        }
        return res;
    }
};



/*
解法二：双指针
枚举子串的中间位置i，从 0 ~ s.size() - 1
左指针从中间位置往左走，右指针从中间位置往右走
如果左右指针left、right都在边界内(0 ~ s.size() - 1 )且s[left] == s[right]
那么左右指针就接着往左右走，如果回文子串长度大于res，就更新res。
注意要分子串长度是奇数和偶数这两种情况讨论
奇数： 初始时 left = i - 1, right = i + 1
偶数： 初始时 left = i, right = i + 1
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); ++i) {
            int left = i - 1, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if(res.size() < right - left - 1) {
                res = s.substr(left + 1, right - left - 1);             //上面的while循环结束时，s[left]和s[right]并不是回文字子串的一部分
                //所以子串的起始位置为left + 1, 子串长度是 (right - 1) + 1 - (left + 1), 也就是 right - left - 1
            }
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {   //这个while循环以及下面的if和子串长度为奇数时完全相同
                left--;
                right++;
            }
            if(res.size() < right - left - 1) {
                res = s.substr(left + 1, right - left - 1);
            }
        }
        return res;
    }
};

/*
解法二的时间复杂度远高于解法一
*/
