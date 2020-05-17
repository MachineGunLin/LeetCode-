class Solution {
public:
    bool isSubset(vector<string>& a, vector<string>& b) {     //判断数组b是否是数组a的子集。 注意传入的两个字符串数组a和b都是已经排序好的数组。
        int j = 0;
        for(int i = 0; i < a.size() && j < b.size(); ++i) {
            if(a[i] == b[j]) {
                j++;
            }
        }
        return j == b.size();
    }
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> res;
        for(auto& fc :favoriteCompanies) {
            sort(fc.begin(), fc.end());
        }
        for(int i = 0; i < favoriteCompanies.size(); ++i) {
            int j = 0;
            for(; j < favoriteCompanies.size(); ++j) {
                if(i == j) {
                    continue;
                }
                if(isSubset(favoriteCompanies[j], favoriteCompanies[i])) {  //如果发现第i个数组是第j个数组(i != j)的子集，就退出循环
                    break;
                }
                
            }
            if(j == favoriteCompanies.size()) {       //如果第i个数组不是其他任何一个数组的子集
                res.push_back(i);             //就把i压入结果数组
            }
        }
        return res;
    }
};
