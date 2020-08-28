class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(citations[i] >= n - i) {
                res = max(res, n - i);
            } else {
                break;
            }
        }
        return res;
    }
};
