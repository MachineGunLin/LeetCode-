class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<string> st;
        for(auto op : ops) {
            st.push(op);
            if(op == "C") {
                st.pop();
                st.pop();
            }
        }
        for(int i = 0; i < ops.size(); ++i) {
            ops[i] = "";
        }
        int index = 0;
        while(!st.empty()) {
            ops[index++] = st.top();
            st.pop();
        }
        reverse(ops.begin(), ops.end());
        vector<int> scores(ops.size(), 0);
        for(int i = 0; i < ops.size(); ++i) {
            if(ops[i] != "D" && ops[i] != "+") {
                scores[i] = atoi(ops[i].c_str());
            }
            if(ops[i] == "D") {
                scores[i] = scores[i - 1] * 2;
            }
            if(ops[i] == "+") {
                scores[i] = scores[i - 2] + scores[i - 1];
            }
            res += scores[i];
        }
        return res;
    }
};
