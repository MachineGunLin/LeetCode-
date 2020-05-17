class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string stack1 = "", stack2 = "";
        for(auto s : S) {
            if(s == '#' && stack1 != "") {
                stack1.pop_back();
            } else if(s != '#') {
                stack1.push_back(s);
            }
        }
        for(auto t : T) {
            if(t == '#' && stack2 != "") {
                stack2.pop_back();
            } else if(t != '#') {
                stack2.push_back(t);
            }
        }
        return stack1 == stack2;
    }
};
