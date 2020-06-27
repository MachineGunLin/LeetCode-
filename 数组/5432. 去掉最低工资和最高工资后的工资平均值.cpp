class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        vector<int> newSalary;
        for(int i = 1; i < salary.size() - 1; ++i) {
            newSalary.push_back(salary[i]);
        }
        double res = 0;
        for(int i = 0; i < newSalary.size(); ++i) {
            res += newSalary[i];
        }
        res /= newSalary.size();
        return res;
    }
};
