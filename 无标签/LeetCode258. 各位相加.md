# LeetCode258. 各位相加

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200821155253595-424889242.png)

如果不考虑进阶的条件，可以直接循环或者递归，把一位上的所有数字加起来然后对10取余。

```
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num >= 10) {
            sum = 0;
            while(num != 0) {
                int temp = num % 10;
                sum += temp;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
```

不过进阶要求我们不能用循环或者递归。
实际上，计算所有位上的数字有一个数学方法。

 ![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200821161226367-1638134221.png)

```
class Solution {
public:
    int addDigits(int num) {
        if(num % 9 == 0 && num != 0) {
            return 9;
        }
        return num % 9;
    }
};
```

实际上，上面代码可以压缩到一行里：

```
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
```