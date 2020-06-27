class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factor;
        factor.push_back(1);
        for(int i = 2; i < n; ++i) {
            if(n % i == 0) {
                factor.push_back(i);
            }
        }
        factor.push_back(n);
        int size = factor.size();
        if(size < k) {
            return -1;
        } else {
            return factor[k - 1];
        }
    }
};
