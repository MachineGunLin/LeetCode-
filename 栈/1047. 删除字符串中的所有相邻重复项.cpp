class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for(auto s : S) {
            if(res.empty() || s != res.back()) {
                res.push_back(s);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};
