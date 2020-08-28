/*
英文里每三位就有个逗号，所以我们单独写一个函数处理每三位数之间的表示，然后再根据当前处理的三位数的位数来决定后面是否要加上"thousand"，"million"啥的。
*/

class Solution {
public:
    unordered_map<int, string> numInEnglish;        // 把一些常见的数字的英文单词记录在一个哈希表里
    string smallNumberToWords(int num) {            // 小于1000的数转换为字符串
        string res = "";
        if(num >= 100) {                                    // 三位数需要加上"Hundred"
            res += (numInEnglish[num / 100] + " " + "Hundred");  
            num = num % 100;
            if(num % 100 != 0) {
                res += " ";
            }
        }
        if(num >= 20) {                                    // 要注意一下大于20的数和10~10的数是由专门的单词的
            res += numInEnglish[(num / 10) * 10];
            num = num % 10;
            if(num != 0) {
                res += " ";
            }
        } 
        if(num >= 10) {                        
            res += numInEnglish[num];
            num = 0;
        }
        if(num > 0) {                                      // 0～9也有专门的单词
            res += numInEnglish[num];
        }
        return res;
    }

    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }
        numInEnglish[1] = "One", numInEnglish[2] = "Two", numInEnglish[3] = "Three", numInEnglish[4] = "Four", 
        numInEnglish[5] = "Five", numInEnglish[6] = "Six", numInEnglish[7] = "Seven", numInEnglish[8] = "Eight",
        numInEnglish[9] = "Nine", numInEnglish[10] = "Ten", numInEnglish[11] = "Eleven", numInEnglish[12] = "Twelve",
        numInEnglish[13] = "Thirteen", numInEnglish[14] = "Fourteen", numInEnglish[15] = "Fifteen", 
        numInEnglish[16] = "Sixteen", numInEnglish[17] = "Seventeen", numInEnglish[18] = "Eighteen",
        numInEnglish[19] = "Nineteen", numInEnglish[20] = "Twenty", numInEnglish[30] = "Thirty",
        numInEnglish[40] = "Forty", numInEnglish[50] = "Fifty", numInEnglish[60] = "Sixty", numInEnglish[70] = "Seventy",
        numInEnglish[80] = "Eighty", numInEnglish[90] = "Ninety";
        string res = "";
        string numToStr = to_string(num);
        int numLen = numToStr.size();
        if(numLen > 9) {                                                           // 先处理大于1e9的部分，因为这题数值最大是INT_MAX,也就是21亿左右，所以不用考虑超过billion三个量级的数字的英文表示
            int howManyBillions = num / 1e9;
            res += (smallNumberToWords(howManyBillions) + " Billion");             // 高于billion的数字用smallNumberToWords单独处理一下英文表示，后面加上"Billion"
            num = num % 1000000000;
            if(num != 0) {
                res += " ";
            } else {
                return res;
            }
        } 
        if(numLen > 6) {                                                           // 这部分和上面同理
            int howManyMillions = num / 1e6;
            if(howManyMillions != 0) {
                res += (smallNumberToWords(howManyMillions) + " Million");
                num = num % 1000000;
                if(num != 0) {
                    res += " ";
                } else {
                    return res;
                }
            } else {
                num = num % 1000000;
            }
        }
        if(numLen > 3) {
            int howManyThousands = num / 1e3;
            if(howManyThousands != 0) {
                res += (smallNumberToWords(howManyThousands) + " Thousand");
                num = num % 1000;
                if(num != 0) {
                    res += " ";
                } else {
                    return res;
                }
            } else {
                num = num % 1000;
            }
        }
        res += smallNumberToWords(num);                                          // 低于千位的部分直接用smallNumberToWords处理即可，后面不需要加上单词
        return res;
    }
};
