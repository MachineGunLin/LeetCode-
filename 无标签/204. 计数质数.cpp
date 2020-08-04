class Solution {
public:
    bool isPrime(int n) {
        if(n == 2) {
            return true;
        }
        for(int i = 2; i * i <= n; ++i) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        if(n < 3) {
            return 0;
        }
        if(n == 3) {
            return 1;
        }
        int res = 1;
        for(int i = 3; i < n; i += 2) {
            if(isPrime(i)) {
                ++res;
            }
        }
        return res;
    }
};
