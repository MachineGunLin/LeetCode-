/*
写一个cmp函数定义排序规则，数组排序之后输出前k个元素。
*/

int midNum;
bool cmp(int a, int b) {            //注意leetcode sort函数需要的cmp函数放到class外面
    if(abs(a - midNum) != abs(b - midNum)) {
        return abs(a - midNum) > abs(b - midNum);
    }
    return a > b;
}
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());                 //原数组可能是无序的，需要先排序
        midNum = arr[(arr.size() - 1) / 2];
        sort(arr.begin(), arr.end(), cmp);
        return vector<int>({arr.begin(), arr.begin() + k});
    }
};

/*
方法二：用lamba表达式（C++17），不写cmp函数。
*/

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int midNum = arr[(arr.size() - 1) / 2];
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if(abs(a - midNum) != abs(b - midNum)) {
                return abs(a - midNum) > abs(b - midNum);
            }
            return a > b;
        });
        return vector<int>({arr.begin(), arr.begin() + k});
    }
};
