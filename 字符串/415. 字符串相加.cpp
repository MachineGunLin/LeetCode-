/*
几千位的字符串，肯定不能转成数字再加了（也转不了），不过还好只要做加法，可以对每一位进行加法，注意进位即可。

可以把两个字符串右对齐，然后对每一位进行加法，每一位计算出来的数字加到一个结果字符串里，这样计算完成后（遍历完num1和num2以及进位为0了），
就把字符串反转一遍，就得到了两个字符串相加的结果。
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1;            //右对齐，从低位往高位做加法
        int t = 0;                                                //t表示进位
        while(i >= 0 || j >= 0 || t != 0) {                        
            int number1 = i >= 0 ? num1[i] - '0' : 0;              //num1当前的数字，如果已经超过了num1的长度，就用0代替，num2同理
            int number2 = j >= 0 ? num2[j] - '0' : 0;
            int curSum = number1 + number2 + t;                  //当前位置，两个数相加的和
            t = curSum / 10;                                    //因为和可能超过了10，所以需要计算进位
            res += ('0' + curSum % 10);                          //当前位的数字是两个数的和对10取余
            --i, --j;                                            //继续往高位计算
        }
        reverse(res.begin(), res.end());                         //因为是从字符串右边开始计算的，得到的字符串需要翻转之后才是我们要的结果
        return res;
    }
};
