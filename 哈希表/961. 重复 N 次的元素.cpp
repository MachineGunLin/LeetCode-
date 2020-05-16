class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> s;
        for(auto a : A) {
            if(s.count(a) != 0) {
                return a;
            } else {
                s.insert(a);
            }
        }
        return 0;
    }
};
