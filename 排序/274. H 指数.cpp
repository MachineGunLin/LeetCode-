/*
对所有citations排序，然后从大到小找第一个满足条件的那个citations就是H指数。
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        int n = citations.size();
        citations.push_back(0);
        sort(citations.begin(), citations.end());
        for(int i = n; i >= 1; --i) {
            if(citations[i] >= n - i + 1) {
                res = max(res, n - i + 1);
            } else {
                break;
            }
        }
        return res;
    }
};
