/*
耍赖做法：
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};


/*
双指针解法：
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
