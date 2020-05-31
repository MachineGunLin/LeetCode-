/*
枚举i从1 ~ n, j从1 ~ i -1
如果i和j的最大公约数，那么j / i就是最简分数，压入res中。
*/

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                if(gcd(i, j) == 1) {
                    res.push_back(to_string(j) + '/' +to_string(i));
                }
            }
        }
        return res;
    }
};
