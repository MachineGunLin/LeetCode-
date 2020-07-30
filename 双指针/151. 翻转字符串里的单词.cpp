/*
题意是要把原字符串中所有的单词划分出来，倒序用一个空格的间隙来连接字符串，我们只需要划分出所有的单词，然后把它们连接起来，每两个单词之间放一个空格就好了。

分割空格之间的单词，很容易想到用双指针进行分割，只需要找到每个单词的第一个字母（也就是第一个不为空格的字母），然后左指针指向这个单词，右指针不断右移直到碰到指向一个空格或者字符串的末尾。

我们额外开一个字符串数组words存放所有划分出来的单词，把每一个划分出来的单词都存在这个数组里，分割出所有的单词之后，翻转一下这个数组，然后把所有单词连接起来（每两个单词之间用一个空格分割），就OK啦。
*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) {
            return "";
        }
        vector<string> words;                              //存放所有划分出来的单词
        for(int i = 0; i < s.size(); ++i) {
            while(s[i] == ' ' && i < s.size()) {           //寻找每个字符串的第一个字母（第一个不为空格的字符）
                ++i;
            }
            if(i == s.size()) {                            //如果左指针i已经到了字符串末尾的下一个位置，说明后面莫得单词了，退出循环
                break;
            }
            int j = i;                                    //j是右指针
            while(s[j] != ' ' && j < s.size()) {           //j指向当前单词的下一个位置（下一个空格或者字符串末尾的下一个位置）
                ++j;
            }
            string temp = s.substr(i, j - i);             //分割出当前的单词
            words.push_back(temp);          
            i = j - 1;                                    //因为循环结束后有一个++i，所以这里将i赋值为j - 1, 这样循环结束后i就是j现在的位置了，可以继续往后寻找单词
        }
        reverse(words.begin(), words.end());               //题目要求翻转单词
        string res;
        for(int i = 0; i < words.size(); ++i) {   
            res += words[i];                                //将所有单词连接起来
            if(i < words.size() - 1) {                    //每两个单词之间有一个空格
                res += ' ';
            }
        }
        return res;
    }
};
