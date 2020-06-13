class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        long res;
        if(x < 0) {
            std::reverse(s.begin() + 1, s.end());
        } else {
            std::reverse(s.begin(), s.end());
        }
        res = stol(s);
        if(res < 2147483647 && res > -2147483648) {
            return res;
        } else {
            return 0;
        }
    }
};
