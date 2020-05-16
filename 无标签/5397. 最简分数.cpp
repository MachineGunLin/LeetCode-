/*
对于所有大于2，小于等于n的 i，现在结果数组中记录"1/i"
然后再对于 2 <= j < i做循环判断，如果i和j的最大公约数为1，
也就说明j / i 是最简分数，那么就在结果数组中记录"j / i"
*/

class Solution {
public:
    int gcd(int a,int b) {
        int c;
        c = (a > b) ? b : a;
        while(a % c != 0 || b % c != 0) {
            c--;
        }
        return c;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if(n == 1) {
            return res;
        }
        
        for(int i = 2; i <= n; ++i) {
            res.push_back("1/" + to_string(i));
            for(int j = 2; j < i; ++j) {
                if(gcd(i, j) == 1) {
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return res;
    }
};
